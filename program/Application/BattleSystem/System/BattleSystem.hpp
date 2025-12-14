#pragma once
#include "System/Utility/Singleton.hpp"
#include "Application/BattleSystem/action/ActionCommand.hpp"
#include "Application/Charactor/Player/Player.hpp"

namespace Battle
{
	class BattleSystem : public Singleton<BattleSystem>
	{
		GENERATE_SINGLETON_BODY(BattleSystem);

	public:
		/// <summary>
		/// バトル中の状態更新
		/// </summary>
		void Update(Chara::Player* player);


		/// <summary>
		/// 終了判定
		/// </summary>
		/// <returns></returns>
		bool IsFinish()const
		{
			return m_isFinishd;
		}

	private:
		/// <summary>
		///	終了しているかどうか
		/// </summary>
		bool m_isFinishd = false;
	};
}