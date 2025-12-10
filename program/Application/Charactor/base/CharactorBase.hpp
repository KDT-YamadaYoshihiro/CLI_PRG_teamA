#pragma once
#include "Application/Charactor/status/CharaStatus.hpp"
#include "System/Utility/Define.hpp"

namespace Chara
{

	/// <summary>
	///	キャラクターのベース
	/// </summary>
	class CharaBase
	{
	public:
		virtual ~CharaBase() = default;

		/// <summary>
		/// ダメージ処理を行う
		/// </summary>
		/// <param name="damage"></param>
		void ApplyDamage(int damage)
		{
			m_status.HP -= damage;
		}

		/*
		* アクセサ
		*/

		//	名前
		PROPERTY(std::string, m_status.Name,Name);
		//	最大体力
		PROPERTY(int, m_status.MaxHP,MaxHp);
		//	今の体力
		PROPERTY(int, m_status.HP,Hp);
		//	物理攻撃力
		PROPERTY(int, m_status.Attack,Attack);
		//	魔法攻撃力
		PROPERTY(int, m_status.MagicAttack,MagicAttack);
		//	防御力
		PROPERTY(int, m_status.Defense,Defence);


		/// <summary>
		/// 死亡判定
		/// </summary>
		/// <returns>true:死亡 false:生存</returns>
		bool IsDead()
		{
			return m_status.HP <= 0;
		}

		/// <summary>
		/// ステータス取得（表示や参照用）
		/// </summary>
		/// <returns></returns>
		const Chara::Status& GetStatus()noexcept
		{
			return m_status;
		}
	protected:
		/// <summary>
		///	ステータス
		/// </summary>
		Chara::Status m_status;

	};
}