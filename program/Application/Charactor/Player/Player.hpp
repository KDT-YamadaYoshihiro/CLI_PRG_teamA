#pragma once
#include"Application/Charactor/base/CharactorBase.hpp"
#include"System/Math/Point/Point.hpp"
#include<vector>


namespace Chara
{
	class Player : public CharaBase
	{
	public:
		/// <summary>
		/// 初期化
		/// </summary>
		/// <param name="Status"></param>
		Player(const Chara::Status& Status);

		/// <summary>
		/// 移動処理
		/// </summary>
		/// <param name="Velocity">移動量</param>
		void Move(const Math::Point& Velocity);

		/// <summary>
		/// 魔法の使用
		/// </summary>

		//	座標
		PROPERTY(Math::Point, m_position,Position);

		/// <summary>
		/// アイテムの使用
		/// </summary>

	private:
		/// <summary>
		///	座標
		/// </summary>
		Math::Point m_position;

		//	魔法（ダメージ等の情報）のコレクション


	};
}

