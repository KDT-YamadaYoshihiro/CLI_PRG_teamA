#include "SceneManager.h"
#include "../program/Scene/DefalutScene/DefalutScene.h"

void SceneManager::Initialize()
{
	//	何もないときにデフォルトを生成
	if(m_currentScene == nullptr)
	{
		// 初期シーンの設定などがあればここで行う
		ChangeScene<DefalutScene>();
	}
	m_currentScene->Initialize();
}

void SceneManager::Update()
{
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

