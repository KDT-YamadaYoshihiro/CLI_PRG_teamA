#pragma once

namespace Battle
{
	//	バトル計算
	class BattleCalc
	{
	public:
		/// <summary>
		/// タメージ計算（ドラクエ11方式）
		/// </summary>
		/// <param name="Attack">攻撃力</param>
		/// <param name="Defence">防御力</param>
		/// <returns>ダメージ値</returns>
		static int CalcDamage(const int Attack,const int Defence)
		{
			//	クリティカルなどをいれるならここで入れてください。
			int attack = Attack;

			//	計算
			int damage = (Attack / 2) - (Defence / 4);

			//	最低保証:１
			return  damage >= 1 ? damage : 1;
		}

		static int CalcMagicDamage(const int MagicPower, const int MagicDamage, const int Defence)
		{
			//	クリティカルなどをいれるならここで入れてください。
			int magicPower = MagicPower;
			//	計算
			int damage = (MagicPower) - (Defence / 4);
			//	最低保証:１
			return  damage >= 1 ? damage : 1;
		}
	};
}
