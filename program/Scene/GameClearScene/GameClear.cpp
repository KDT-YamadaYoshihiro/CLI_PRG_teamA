#include <iostream>
#include <stdlib.h>
#include "GameClear.h"
#include "../../Engine/Engine.hpp"

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
	engine->GetView()->ClearScene();

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