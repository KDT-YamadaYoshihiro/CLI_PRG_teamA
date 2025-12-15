#include <iostream>
#include <stdlib.h>
#include "Title.h"
#include "../../Engine/Engine.hpp"

// コンストラクタ・デストラクタ
TitleScene::TitleScene()
{
}
TitleScene::~TitleScene()
{
	this->Release();
}

// 初期化
void TitleScene::Initialize()
{
	engine->GetView()->ClearScene();

	engine->GetView()->AddLine(" ------------------------------------------------------ ");
	engine->GetView()->AddLine(" ---   #####  #       ###   ######  ######   #####  --- ");
	engine->GetView()->AddLine(" ---  #     # #        #    #     # #     # #     # --- ");
	engine->GetView()->AddLine(" ---  #       #        #    ######  ######  #       --- ");
	engine->GetView()->AddLine(" ---  #       #        #    #   #   #       #  #### --- ");
	engine->GetView()->AddLine(" ---  #     # #        #    #    #  #       #     # --- ");
	engine->GetView()->AddLine(" ---   #####  ####### ###   #     # #        #####  --- ");
	engine->GetView()->AddLine(" ------------------------------------------------------ ");
	engine->GetView()->AddLine(" ---             Ket Push to Game START             --- ");
}

// 更新
void TitleScene::Update()
{
}

// 描画
void TitleScene::Render()
{
	
}

// 解放
void TitleScene::Release()
{
	// コンソール画面のリセット
	std::system("cls");
}