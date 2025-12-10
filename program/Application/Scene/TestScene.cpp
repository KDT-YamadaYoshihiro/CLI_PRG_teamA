#include "TestScene.hpp"
#include "Engine/Engine.hpp"

#include "Application/BattleSystem/action/ActionCommand.hpp"

std::vector<std::string> g_testNames;

#include <iostream>

void TestScene::Initialize()
{
	CLI_ENGINE->GetView()->AddLine("ÉeÉXÉgâÊñ ÇÃê∂ê¨");


	g_testNames.reserve(9);
	g_testNames.push_back("1Ç≠ÇÒ");
	g_testNames.push_back("2Ç≠ÇÒ");
	g_testNames.push_back("3Ç≠ÇÒ");
	g_testNames.push_back("4Ç≠ÇÒ");
	g_testNames.push_back("5Ç≠ÇÒ");
	g_testNames.push_back("6Ç≠ÇÒ");
	g_testNames.push_back("7Ç≠ÇÒ");
	g_testNames.push_back("8Ç≠ÇÒ");
	g_testNames.push_back("9Ç≠ÇÒ");
}

void TestScene::Update()
{
	auto result = Battle::ActionSelector::SelectCommand(g_testNames, g_testNames);
	if (result.command != Battle::ePlayerCommand::Attack)
	{
		std::cout << g_testNames[result.selectID] << std::endl;
	}
}

void TestScene::Render()
{
}

void TestScene::Release()
{
}
