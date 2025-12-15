#include <iostream>
#include <stdlib.h>
#include "GameClear.h"
#include "../../Engine/Engine.hpp"

#include "System/Input/Key.hpp"
#include "Scene/SceneManager.h"
#include "Scene/TitleScene/Title.h"

// コンストラクタ・デストラクタ
GameClearScene::GameClearScene()
{
}

GameClearScene::~GameClearScene()
{
	this->Release();
}

// 初期化
void GameClearScene::Initialize()
{
	engine->GetView()->ClearLines();

	engine->GetView()->AddLine(" ------------------------------------------------------------------------------- ");
	engine->GetView()->AddLine(" ---   #####    #   #     # #######     #####  #       #######   #   ######  --- ");
	engine->GetView()->AddLine(" ---  #     #  # #  ##   ## #          #     # #       #        # #  #     # --- ");
	engine->GetView()->AddLine(" ---  #       #   # # # # # #####      #       #       #####   #   # ######  --- ");
	engine->GetView()->AddLine(" ---  #  #### ##### #  #  # #          #       #       #       ##### #   #   --- ");
	engine->GetView()->AddLine(" ---  #     # #   # #     # #          #     # #       #       #   # #    #  --- ");
	engine->GetView()->AddLine(" ---   #####  #   # #     # #######     #####  ####### ####### #   # #     # --- ");
	engine->GetView()->AddLine(" ------------------------------------------------------------------------------- ");
}

// 更新
void GameClearScene::Update()
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
void GameClearScene::Render()
{
	
}

// 解放
void GameClearScene::Release()
{
	// コンソール画面のリセット
	std::system("cls");
}