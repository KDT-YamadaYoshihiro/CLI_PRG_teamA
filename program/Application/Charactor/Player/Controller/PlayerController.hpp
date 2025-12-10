#pragma once
#include"System/Math/Point/Point.hpp"

namespace Player
{
	/// <summary>0
	/// 入力から移動量を取得するだけ
	/// その移動量を外側に渡すことで移動できるかの判定をしてもらう
	/// </summary>
	class Controller
	{
	public:
		/// <summary>
		/// 移動ロジック
		/// </summary>
		/// <returns>移動量</returns>
		static Math::Point GetInputVelocity();
	};
}