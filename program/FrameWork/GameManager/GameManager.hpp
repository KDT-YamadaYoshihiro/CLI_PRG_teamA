#pragma once
#include "System/Utility/Singleton.hpp"

namespace Engine
{
	class GameManager : public Singleton<GameManager>
	{
	public:
		GENERATE_SINGLETON_BODY(GameManager)

		bool Initialize();		
		void Run();
		void Finalize();

	private:
		void OnCreate()override;
		void OnDestory()override;
	private:
		bool m_running;
	};

}
