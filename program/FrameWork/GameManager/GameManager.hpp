#pragma once
#include "System/Utility/Singleton.hpp"

namespace Engine
{
	class GameManager : public Singleton<GameManager>
	{
		GENERATE_SINGLETON_BODY(GameManager)
	public:
		bool Initialize();		
		void Run();
		void Finalize();

		/// <summary>
		/// ç≈èâÇÃSceneÇÃê∂ê¨
		/// </summary>
		void CreateStartScene();
	private:
		void OnCreate()override;
		void OnDestory()override;
	private:
		bool m_running;
	};

}
