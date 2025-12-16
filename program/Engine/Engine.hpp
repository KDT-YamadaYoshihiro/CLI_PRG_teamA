#pragma once
#include "System/Utility/Singleton.hpp"
#include "Graphics/View/View.hpp"
#include "FrameWork/GameManager/GameManager.hpp"
#include "System/Utility/Define.hpp"
#include "System/Time/Time.hpp"

#include<memory>

#ifndef CLI_ENGINE
#define CLI_ENGINE Engine::Engine::GetInstance()
#endif // !CLI_ENGINE

namespace Engine
{
	class Engine : public Singleton<Engine>
	{
		GENERATE_SINGLETON_BODY(Engine)

		void OnCreate()override;
		void OnDestory()override;

	public:
		/// <summary>
		///	初期化
		/// </summary>
		/// <returns>true:成功</returns>
		bool Initialize();

		/// <summary>
		/// ゲームマネージャーの取得
		/// </summary>
		/// <returns></returns>
		GameManager* GetGameManager()noexcept;

		/// <summary>
		/// ビューの所得
		/// </summary>
		/// <returns></returns>
		Graphics::View* GetView()noexcept;

		/// <summary>
		/// フレーム管理
		/// </summary>
		/// <returns></returns>
		Time* GetTimer()noexcept;

	private:
		/// <summary>
		/// ゲームマネージャーの生成と初期化
		/// </summary>
		/// <returns></returns>
		bool InitializeGameManager();

		/// <summary>
		/// ビューの生成と初期化
		/// </summary>
		/// <returns></returns>
		bool InitializeView();

		/// <summary>
		/// フレームの制御を管理する
		/// </summary>
		/// <returns></returns>
		bool InitializeTimer();

		/// <summary>
		/// スクリーン管理の初期火
		/// </summary>
		/// <returns>true:成功</returns>
		bool InitializeSceneManager();

	private:
		GameManager* m_gameManager;
		Graphics::View* m_view;
		std::unique_ptr<Time> m_timer;
	};
}
