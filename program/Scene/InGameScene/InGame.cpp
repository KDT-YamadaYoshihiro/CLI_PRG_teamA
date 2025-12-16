#include <iostream>
#include <stdlib.h>
#include "InGame.h"

#include "Application/BattleSystem/System/BattleSystem.hpp"
#include "Application/Charactor/Player/Controller/PlayerController.hpp"
#include "Graphics/View/View.hpp"
#include "System/Input/Key.hpp"
#include "Engine/Engine.hpp"
#include "Scene/SceneManager.h"

#include "System/CSV/MapLoder.h"
#include "Application/Charactor/Factory/Factory.h"
#include "System/Utility/Random.hpp"

#include "Scene/GameOverScene/GameOver.h"
#include "Scene/GameClearScene/GameClear.h"

#include "Application/Inventory/Item/Healing_Item/Item_Healing.h"


void InGameScene::RenderMapWithPlayer()
{
	CLI_ENGINE->GetView()->ClearLines();
	CLI_ENGINE->GetView()->AddLine(std::to_string(m_mapNum) + "階層目 / " + std::to_string(STATE_MAX) + "階層");

	//	プレイヤーの表示位置を更新する
	Math::Point position = m_player->GetPosition();

	std::vector<std::string> temp_mapline;

	temp_mapline = m_map.GetLines();
	temp_mapline[position.y][position.x] = 'P';

	//	表示するプレイヤーの番号の所だけ変更する
	for (auto line : temp_mapline)
	{
		Graphics::View::GetInstance()->AddLine(line);
	}
}

void InGameScene::RenderMap()
{
	std::vector<std::string> temp_mapline;

	temp_mapline = m_map.GetLines();

	//	表示するプレイヤーの番号の所だけ変更する
	for (auto line : temp_mapline)
	{
		Graphics::View::GetInstance()->AddLine(line);
	}
}

void InGameScene::MoveToNextFloor()
{
	//	データの読み込み
	char filePath[64];
	sprintf_s(filePath, "Assets/MapData/Mapdata_%d.csv", m_mapNum);
	std::vector<std::vector<int>> data = MapLoder::Load(filePath);
	data.resize(10);
	for (auto& line : data)
	{
		line.resize(20);
	}
	m_map.SetMapData(data);

	//	プレイヤーは1,1スタートで
	m_player->SetPosition({ 1,1 });

	RenderMapWithPlayer();
}

/// <summary>
/// 敵の生成
/// </summary>
void InGameScene::CreateEnemy()
{
	m_enemys.clear();

	int create_num = Random::Range(1, 3);
	for (size_t i = 0; i < create_num;i++)
	{
		int status_num = Random::Range(1, 2);
		m_enemys.push_back(Chara::Factory::GetInstance()->CreateCharacter<Chara::Enemy>(status_num));
	}
}

// コンストラクタ・デストラクタ
InGameScene::InGameScene()
{
}

InGameScene::~InGameScene()
{
	this->Release();
}

// 初期化
void InGameScene::Initialize()
{
	Battle::BattleSystem::Create();
	Chara::Factory::Create();
	//	今はファクトリ実装前なのでこのようにしてやります。
	m_player = Chara::Factory::GetInstance()->CreateCharacter<Chara::Player>(0);
	//CreateEnemy();
	m_inventoryManager = std::make_unique<Inventory::InventoryManager>();

	m_inventoryManager->AddItem(std::make_unique<Inventory::Item_Healing>("初級ポーション",30));
	m_inventoryManager->AddItem(std::make_unique<Inventory::Item_Healing>("初級ポーション",30));
	m_inventoryManager->AddItem(std::make_unique<Inventory::Item_Healing>("初級ポーション",30));
	m_inventoryManager->AddItem(std::make_unique<Inventory::Item_Healing>("中級ポーション", 50));
	m_inventoryManager->AddItem(std::make_unique<Inventory::Item_Healing>("中級ポーション", 50));
	m_inventoryManager->AddItem(std::make_unique<Inventory::Item_Healing>("上級ポーション", 120));


	// 初期のマップデータ
	std::vector<std::vector<int>> data = MapLoder::Load("Assets/MapData/MapData_1.csv");
	data.resize(10);
	for (auto& line : data)
	{
		line.resize(20);
	}
	
	m_map.SetMapData(data);

	//	プレイヤーは1,1スタートで
	m_player->SetPosition({ 1,1 });
	RenderMapWithPlayer();
}
	
// 更新
void InGameScene::Update()
{
	switch (m_state)
	{
	case Game::GameState::Field:

#ifdef _DEBUG
		//	キー入力でバトル切り替える
		if (_kbhit())
		{
			if (Input::GetKey().code == Input::KeyCode::Space)
			{
				m_state = Game::GameState::Battle;
			}
		}
#endif // _DEBUG

		{
			//	プレイヤーの移動入力
			Math::Point velocity = Player::Controller::GetInputVelocity();
			Math::Point next = m_player->GetPosition() + velocity;
			//	移動入力があったかどうかの判定
			if (velocity == Math::Point::Zero)
			{
				return;
			}

			//	移動できるかどうかの判定
			if (m_map.CanMove(next) == false)
			{
				return;
			}

			////	文字列をすべて削除
			Graphics::View::GetInstance()->ClearLines();

			m_map.UpdateMapString();

			//	移動できるならプレイヤーの移動をして
			m_player->Move(velocity);

			RenderMapWithPlayer();


			// 階段かどうか
			if (m_map.IsPlayerAtStairs(next))
			{
				//CLI_ENGINE->GetTimer()->Sleep(std::chrono::milliseconds(10));

				//	階層の番号のインクリメント
				m_mapNum++;

				//	番号のインクリメント
				if (STATE_MAX < m_mapNum)
				{
					//	ゲームクリアのシーンに変更する
					SceneManager::GetInstance()->ChangeScene<GameClearScene>();
					return;
				}

				//	次の階層にする
				this->MoveToNextFloor();

				return;
			}

		}
		//	移動したらランダムエンカウント（確率）
			//	エンカウントした場合は、バトル状態にする	
			//	しなかった場合は上に戻る
		if (encount.IsEncount())
		{
			//	切り替え
			m_state = Game::GameState::Battle;

			//	敵の生成
			CreateEnemy();

			//	エンカウント通知
			CLI_ENGINE->GetView()->AddLine("敵が飛び出してきた！");
			CLI_ENGINE->GetView()->Render();
			CLI_ENGINE->GetTimer()->Sleep(std::chrono::seconds(1));
		}


		break;
	case Game::GameState::Battle:
	{
		std::vector<Chara::Enemy*> tep_enemys;
		tep_enemys.reserve(m_enemys.size());
		for (auto& enemy : m_enemys)
		{
			tep_enemys.push_back(enemy.get());
		}

		Battle::BattleSystem::GetInstance()->Update(m_player.get(), tep_enemys,m_inventoryManager.get());
		
		//	敵をコレクションから削除する
		std::erase_if(
			m_enemys,
			[](const std::unique_ptr<Chara::Enemy>& enemy)
			{
				return enemy->GetHp() <= 0;
			});

		//	プレイヤーが生存しているかどうか
		if (m_player->IsDead())
		{
			/*
			* ゲームオーバーに飛ばす
			*/
			SceneManager::GetInstance()->ChangeScene<GameOverScene>();

			return;
		}

		//	バトル終了していてまだプレイヤーが死亡していなかったら
		if (Battle::BattleSystem::GetInstance()->IsFinish())
		{
			m_state = Game::GameState::Field;
			CLI_ENGINE->GetView()->ClearLines();
			this->RenderMapWithPlayer();
		}

	}
		break;
	default:
		break;
	}
}
	
// 描画
void InGameScene::Render()
{
}

// 解放
void InGameScene::Release()
{
	// コンソール画面のリセット
	std::system("cls");
}
