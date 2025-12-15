#include <iostream>
#include <stdlib.h>
#include "Title.h"
#include "../../Engine/Engine.hpp"

#include "Scene/SceneManager.h"
#include "Scene/InGameScene/InGame.h"

#include "System/Input/Key.hpp"

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
	engine->GetView()->ClearLines();

	engine->GetView()->AddLine(" ------------------------------------------------------ ");
	engine->GetView()->AddLine(" ---   #####  #       ###   ######  ######   #####  --- ");
	engine->GetView()->AddLine(" ---  #     # #        #    #     # #     # #     # --- ");
	engine->GetView()->AddLine(" ---  #       #        #    ######  ######  #       --- ");
	engine->GetView()->AddLine(" ---  #       #        #    #   #   #       #  #### --- ");
	engine->GetView()->AddLine(" ---  #     # #        #    #    #  #       #     # --- ");
	engine->GetView()->AddLine(" ---   #####  ####### ###   #     # #        #####  --- ");
	engine->GetView()->AddLine(" ------------------------------------------------------ ");
	engine->GetView()->AddLine(" ---            SPACE Ket Push to Game START        --- ");
}

// 更新
void TitleScene::Update()
{
	if (_kbhit())
	{
		if (Input::GetKey().code == Input::KeyCode::Space)
		{
			SceneManager::GetInstance()->ChangeScene<InGameScene>();
			return;
		}
	}
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