#include "GameClear.hpp"

#include"Engine/Engine.hpp"
#include"System/Input/Key.hpp"
#include"Scene/SceneManager.h"
#include"Scene/TitleScene/Title.h"

void GameClearScene::Initialize()
{
	CLI_ENGINE->GetView()->ClearLines();
	CLI_ENGINE->GetView()->AddLine("ボス討伐：ゲームクリア");
	CLI_ENGINE->GetView()->AddLine("終了：Space で終了します");

}

void GameClearScene::Update()
{
	//	キー入力で終了処理
	if (_kbhit())
	{
		if (Input::GetKey().code == Input::KeyCode::Space)
		{
			CLI_ENGINE->GetTimer()->Sleep(std::chrono::seconds(1));
			SceneManager::GetInstance()->ChangeScene<TitleScene>();
		}
	}

}
