#pragma once

namespace Game::MapSystem
{
	//	マップのコード
	enum class TileType : int
	{
		Road = 0,	//	道
		Wall,	//	壁
		Stairm	//	階段
	};
}