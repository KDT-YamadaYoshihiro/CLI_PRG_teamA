#include "SceneManager.h"
#include "../System/Input/Key.hpp"
#include "../program/Scene/DefalutScene/DefalutScene.h"
#include "InGameScene/InGame.h"
#include "TitleScene/Title.h"

void SceneManager::Initialize()
{
	//	何もないときにデフォルトを生成
	if(m_currentScene == nullptr)
	{
		// 初期シーンの設定などがあればここで行う
		ChangeScene<TitleScene>();
	}
	m_currentScene->Initialize();
}

void SceneManager::Update()
{
	// キーの入力
	if(Input::GetKey().code == Input::KeyCode::Enter)
	{
		ChangeScene<InGameScene>();
	}

	if (m_currentScene)
	{
		m_currentScene->Update();
	}
}

void SceneManager::Render()
{
	if (m_currentScene)
	{
		m_currentScene->Render();
	}
}

void SceneManager::Release()
{
	if (m_currentScene)
	{
		m_currentScene->Release();
		m_currentScene.reset();
	}
}

