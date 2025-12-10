#pragma once
#include<compare>

namespace Math
{
	class Point
	{
	public:
		int x;
		int y;

		static const Point Up;
		static const Point Down;
		static const Point Left;
		static const Point Right;

		//	==,!=,<,<=,>,>=のオーバーロード
		auto operator<=>(const Point& other) const = default;

		Point& operator+=(const Point& other)
		{
			this->x += other.x;
			this->y += other.y;
			return *this;
		}

	};
}