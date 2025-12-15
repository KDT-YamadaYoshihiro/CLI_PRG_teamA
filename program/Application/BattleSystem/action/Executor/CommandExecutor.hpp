#pragma once
#include "Application/Charactor/Player/Player.hpp"
#include "Application/BattleSystem/action/ActionCommand.hpp"

namespace Battle
{
	/// <summary>
	/// 選択されたコマンドの処理
	/// </summary>
	class CommandExcutor
	{
	public:
		//	後から敵の追加をします
		static void Excute(const ActionResult& result, Chara::Player* player);

	private:
		//	攻撃

		//	魔法

		//	アイテム使用

	};

}
