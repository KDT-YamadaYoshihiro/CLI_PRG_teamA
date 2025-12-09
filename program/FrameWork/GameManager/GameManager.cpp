#include "GameManager.hpp"

#include "Graphics/View/View.hpp"
#include "Engine/Engine.hpp"

bool Engine::GameManager::Initialize()
{
	return true;
}

void Engine::GameManager::Run()
{
	while (m_running == true)
	{
		//	時間更新

		//	クリア
		Graphics::View::GetInstance()->ClearBuffer();

		//	スクリーン更新

		Graphics::View::GetInstance()->Render();

		//	フレーム制御
		Engine::GetInstance()->GetTimer()->Wait();

		//	画面のフリップ
		Graphics::View::GetInstance()->Flip();
	}
}

void Engine::GameManager::Finalize()
{

}

void Engine::GameManager::OnCreate()
{
	m_running = true;
}

void Engine::GameManager::OnDestory()
{
}
