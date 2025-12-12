#include <iostream>
#include <stdlib.h>
#include "InGame.h"

#include "Application/BattleSystem/System/BattleSystem.hpp"
#include "Application/Charactor/Player/Controller/PlayerController.hpp"
#include "Graphics/View/View.hpp"


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
	data[0].resize(10);
	m_map.SetMapData(data);
	m_map.UpdateMapString();
	for (auto line : m_map.GetLines())
	{
		Graphics::View::GetInstance()->AddLine(line);
	}
}
	
// 更新
void InGameScene::Update()
{
	switch (m_state)
	{
	case Game::GameState::Field:
		{
		//	プレイヤーの移動入力
		Math::Point next = Player::Controller::GetInputVelocity();

		//	移動入力があったかどうかの判定
		if (next == Math::Point::Zero)
		{
			return;
		}
			
		//	移動できるかどうかの判定
		if (m_map.CanMove(next) == false)
		{
			return;
		}

		//	文字列をすべて削除
		Graphics::View::GetInstance()->ClearLines();

		//	移動できるならプレイヤーの移動をして
		m_player->Move(next);
		
		//	プレイヤーの表示位置を更新する
		Math::Point position = m_player->GetPosition();
			


		}

		//	移動したらランダムエンカウント（確率）
			//	エンカウントした場合は、バトル状態にする	
			//	しなかった場合は上に戻る

		break;
	case Game::GameState::Battle:
		Battle::BattleSystem::GetInstance()->Update();
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
