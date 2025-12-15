#include <iostream>
#include <stdlib.h>
#include "InGame.h"

#include "Application/BattleSystem/System/BattleSystem.hpp"
#include "Application/Charactor/Player/Controller/PlayerController.hpp"
#include "Graphics/View/View.hpp"
#include "System/Input/Key.hpp"
#include "Engine/Engine.hpp"
#include "Scene/SceneManager.h"

#include "Scene/GameClear/GameClear.hpp"

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
	//	今は読込がないので仮のマップ生成
	std::vector<std::vector<int>> data;
	data.resize(10);
	for (auto& line : data)
	{
		line.resize(10);
	}
	data[5][5] = 2;
	m_map.SetMapData(data);

	//	プレイヤーは0,0スタートで
	m_player->SetPosition({ 0,0 });

	RenderMapWithPlayer();
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

	//	今はファクトリ実装前なのでこのようにしてやります。
	m_player = std::make_unique<Chara::Player>(Chara::Status{});

	//	仮のマップ生成
	std::vector<std::vector<int>> data;
	data.resize(10);
	for (auto& line : data)
	{
		line.resize(10);
	}
	data[5][5] = 2;
	m_map.SetMapData(data);

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

		break;
	case Game::GameState::Battle:
		Battle::BattleSystem::GetInstance()->Update(m_player.get());
		if (Battle::BattleSystem::GetInstance()->IsFinish())
		{
			m_state = Game::GameState::Field;
			CLI_ENGINE->GetView()->ClearLines();
			this->RenderMapWithPlayer();
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
