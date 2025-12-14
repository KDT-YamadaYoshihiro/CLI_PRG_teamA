#pragma once
#include "Application/Charactor/base/CharactorBase.hpp"

namespace Chara
{
	/// <summary>
	///	エネミークラス
	/// </summary>
	class Enemy : public Chara::CharaBase
	{
		
		public:
		//	初期化
		Enemy(const Chara::Status& Status)
			:CharaBase(Status) {}
		virtual ~Enemy() = default;

		void Attack(Chara::CharaBase& target);

	};
}

