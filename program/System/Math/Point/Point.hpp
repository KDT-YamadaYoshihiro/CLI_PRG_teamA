#pragma once

namespace Math
{
	class Point
	{
	public:
		int x;
		int y;

		//	==,!=,<,<=,>,>=のオーバーロード
		auto operator<=>(const Point& other) const = default;
	};
}