#pragma once
#include "Application/Charactor/status/CharaStatus.hpp"

namespace Chara
{

	/// <summary>
	///	キャラクターのベース
	/// </summary>
	class CharaBase
	{
	public:
		//	ダメージ

		//	体力所得

		//	物理攻撃力取得

		//	魔法攻撃力取得

		//	名前取得

		//	防御力取得

		//	死亡判定



		/// <summary>
		/// ステータス取得（表示や参照用）
		/// </summary>
		/// <returns></returns>
		const Chara::Status& GetStatus()noexcept;
	protected:
		Chara::Status m_status;

	};
}