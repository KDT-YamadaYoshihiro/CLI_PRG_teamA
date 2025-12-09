#include "Engine/Engine.hpp"
#include<iostream>

int main()
{
	Engine::Engine::Create();
	Engine::Engine* Engine = Engine::Engine::GetInstance();
	bool ret = Engine->Initialize();
	if (ret == false)
	{
		std::cout << "ƒGƒ“ƒWƒ“‚Ì‹N“®‚ÉŽ¸”s" << std::endl;
		return -1;
	}
	Engine->GetGameManager()->Run();
	Engine->GetGameManager()->Finalize();
	return 0;
}