#include "GameManager.hpp"

#include "Graphics/View/View.hpp"
#include "Engine/Engine.hpp"
#include "Scene/SceneManager.h"


#include "Scene/DefalutScene/DefalutScene.h"
#include "Application/Scene/TestScene.hpp"
#include "Scene/InGameScene/InGame.h"
#include "Scene/TitleScene/Title.h"
#include "Scene/GameClearScene/GameClear.h"
#include "Scene/GameOverScene/GameOver.h"

#ifdef EXP_SCENE 
#undef EXP_SCENE 
#endif // EXP_SCENE

//	-1:TestScene 0:Default 1:Title 2:InGame 3:End
// 3 にクリアの画面　4 にゲームオーバーの画面　を追加しました
#define EXP_SCENE 4

namespace Debug
{
	void CreateScene()
	{
#if EXP_SCENE == -1
		SceneManager::GetInstance()->ChangeScene<TestScene>();
#elif EXP_SCENE == 0

#elif EXP_SCENE == 1
		SceneManager::GetInstance()->ChangeScene<TitleScene>();

#elif EXP_SCENE == 2
		SceneManager::GetInstance()->ChangeScene<InGameScene>();

#elif EXP_SCENE == 3
		SceneManager::GetInstance()->ChangeScene<GameClearScene>();

#elif EXP_SCENE == 4
		SceneManager::GetInstance()->ChangeScene<GameOverScene>();
		

#else
		SceneManager::GetInstance()->ChangeScene<DefalutScene>();
#endif // EXP_SCENE == 0

	}
}


bool Engine::GameManager::Initialize()
{	
	//	画面生成
	this->CreateStartScene();
	return true;
}

void Engine::GameManager::Run()
{
	while (m_running == true)
	{
		//	時間更新


		//	スクリーン更新
		SceneManager::GetInstance()->Update();
		SceneManager::GetInstance()->Render();

		//	表示する
		 Graphics::View::GetInstance()->Render();

	}
}

void Engine::GameManager::Finalize()
{

}

/// <summary>
/// 最初のSceneの生成
/// </summary>
void Engine::GameManager::CreateStartScene()
{
	/*
	* デバック中はこっちの処理
	*/
#ifdef _DEBUG
	//	テスト用
#if EXP_SCENE == -1
	SceneManager::GetInstance()->ChangeScene<TestScene>();

	//	何もないとき
#elif EXP_SCENE == 0
	SceneManager::GetInstance()->ChangeScene<DefalutScene>();
#elif EXP_SCENE == 1
	SceneManager::GetInstance()->ChangeScene<TitleScene>();
#elif EXP_SCENE == 2
	SceneManager::GetInstance()->ChangeScene<InGameScene>();
#elif EXP_SCENE == 3
	SceneManager::GetInstance()->ChangeScene<GameClearScene>();
#elif EXP_SCENE == 4
	SceneManager::GetInstance()->ChangeScene<GameOverScene>();

	//	該当しない時
#else
#endif // EXP_SCENE == 0

	/*
	* リリースの時はこっちの処理
	*/

#else
	//	タイトルの生成

#endif // _DEBUG
	SceneManager::GetInstance()->Initialize();
}

void Engine::GameManager::OnCreate()
{
	m_running = true;
}

void Engine::GameManager::OnDestory()
{
}
