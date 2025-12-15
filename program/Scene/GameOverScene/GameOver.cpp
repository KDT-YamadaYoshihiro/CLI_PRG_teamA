#include <iostream>
#include <stdlib.h>
#include "GameOver.h"
#include "../../Engine/Engine.hpp"


#include "System/Input/Key.hpp"
#include "Scene/SceneManager.h"
#include "Scene/TitleScene/Title.h"
// コンストラクタ・デストラクタ
GameOverScene::GameOverScene()
{
}

GameOverScene::~GameOverScene()
{
	this->Release();
}

// 初期化
void GameOverScene::Initialize()
{
	engine->GetView()->ClearLines();

	engine->GetView()->AddLine(" -------------------------------------------------------------------------- ");
	engine->GetView()->AddLine(" ---   #####    #   #     # #######     ####### #     # ####### ######  --- ");
	engine->GetView()->AddLine(" ---  #     #  # #  ##   ## #           #     # #     # #       #     # --- ");
	engine->GetView()->AddLine(" ---  #       #   # # # # # #####       #     # #     # #####   ######  --- ");
	engine->GetView()->AddLine(" ---  #  #### ##### #  #  # #           #     #  #   #  #       #   #   --- ");
	engine->GetView()->AddLine(" ---  #     # #   # #     # #           #     #   # #   #       #    #  --- ");
	engine->GetView()->AddLine(" ---   #####  #   # #     # #######     #######    #    ####### #     # --- ");
	engine->GetView()->AddLine(" -------------------------------------------------------------------------- ");
}

// 更新
void GameOverScene::Update()
{
	if (_kbhit())
	{
		if (Input::GetKey().code == Input::KeyCode::Space)
		{
			SceneManager::GetInstance()->ChangeScene<TitleScene>();
			return;
		}
	}
}

// 描画
void GameOverScene::Render()
{
	
}

// 解放
void GameOverScene::Release()
{
	// コンソール画面のリセット
	std::system("cls");
}