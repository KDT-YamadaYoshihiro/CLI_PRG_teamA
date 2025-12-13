#pragma once
#include<compare>

namespace Math
{
	class Point
	{
	public:
		int x = 0;
		int y = 0;

		static const Point Up;
		static const Point Down;
		static const Point Left;
		static const Point Right;
		static const Point Zero;

		//	==,!=,<,<=,>,>=のオーバーロード
		auto operator<=>(const Point& other) const = default;

		Point& operator+=(const Point& other)
		{
			this->x += other.x;
			this->y += other.y;
			return *this;
		}
		Point& operator-=(const Point& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			return *this;
		}

	};

	//	加算
	inline Point operator+(Point lhs, const Point& rhs)
	{
		lhs += rhs;
		return lhs;
	}
	//	減算
	inline Point operator-(Point lhs, const Point& rhs)
	{
		lhs -= rhs;
		return lhs;
	}
}