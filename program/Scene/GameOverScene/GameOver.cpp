#include <iostream>
#include <stdlib.h>
#include "GameOver.h"
#include "../../Engine/Engine.hpp"

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
	engine->GetView()->ClearScene();

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