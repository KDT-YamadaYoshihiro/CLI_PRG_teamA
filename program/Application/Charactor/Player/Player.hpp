#pragma once
#include"Application/Charactor/base/CharactorBase.hpp"
#include"System/Math/Point/Point.hpp"

#include<vector>


namespace Chara
{
	class Player : public CharaBase
	{
	public:
		//	移動
		void Move(const Math::Point& Velocity);

		/// <summary>
		/// 魔法の使用
		/// </summary>

		//	座標
		PROPERTY(Math::Point, m_position);

		//	アイテム使用


	private:
		/// <summary>
		///	座標
		/// </summary>
		Math::Point m_position;

		//	魔法（ダメージ等の情報）のコレクション


	};
}

