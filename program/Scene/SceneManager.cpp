#include "SceneManager.h"
#include "../program/Scene/DefalutScene/DefalutScene.h"

void SceneManager::Initialize()
{
	// ‰ŠúƒV[ƒ“‚Ìİ’è‚È‚Ç‚ª‚ ‚ê‚Î‚±‚±‚Ås‚¤
	ChangeScene<DefalutScene>();
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
		m_currentScene = nullptr;
	}
}

