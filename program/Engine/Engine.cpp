#include "Engine/Engine.hpp"
#include "System/Utility/Define.hpp"

void Engine::Engine::OnCreate()
{
	m_gameManager = nullptr;
	m_view = nullptr;
}

void Engine::Engine::OnDestory()
{

}

bool Engine::Engine::Initialize()
{
	bool ret = false;

	//	GameManager
	ret = this->InitializeGameManager();
	if (ret == false)
	{
		return false;
	}
	//	View
	ret = this->InitializeView();
	if (ret == false)
	{
		return false;
	}
	//	Timer
	ret = this->InitializeTimer();
	if (ret == false)
	{
		return false;
	}

	return true;
}

/// <summary>
/// ゲームマネージャーの取得
/// </summary>
/// <returns></returns>
Engine::GameManager* Engine::Engine::GetGameManager() noexcept
{
	return m_gameManager;
}

/// <summary>
/// フレーム管理
/// </summary>
/// <returns></returns>
Engine::Time* Engine::Engine::GetTimer() noexcept
{
	return m_timer.get();
}

/// <summary>
/// ゲームマネージャーの生成と初期化
/// </summary>
/// <returns></returns>
bool Engine::Engine::InitializeGameManager()
{
	bool ret = false;
	//	ゲームマネージャー
	GameManager::Create();
	m_gameManager = GameManager::GetInstance();
	if (pFAILED(m_gameManager))
	{
		DEBUG_BREAK
		return false;
	}
	ret = m_gameManager->Initialize();
	if (ret == false)
	{
		DEBUG_BREAK
		return false;
	}
	return true;
}

/// <summary>
/// ビューの生成と初期化
/// </summary>
/// <returns></returns>
bool Engine::Engine::InitializeView()
{
	bool ret = false;

	//	ビュー
	Graphics::View::Create();
	m_view = Graphics::View::GetInstance();
	if (pFAILED(m_view))
	{
		DEBUG_BREAK
		return false;
	}
	ret = m_view->Initialize();
	if (ret == false)
	{
		DEBUG_BREAK
		return false;
	}
	m_view->AddString("初期化完了");

	return true;
}

/// <summary>
/// フレームの制御を管理する
/// </summary>
/// <returns></returns>
bool Engine::Engine::InitializeTimer()
{
	m_timer = std::make_unique<Time>();
	if (pFAILED(m_timer))
	{
		return false;
	}

	return true;
}
