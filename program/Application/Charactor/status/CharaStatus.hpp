#pragma once
#include<string>


namespace Chara
{
	/// <summary>
	/// キャラの共通ステータス
	/// </summary>
	struct Status
	{
		std::string Name = "Unknown";
		int HP = 1;
		int Attack = 1;
		int MagicAttack = 1;
		int Defense = 1;
	};
}