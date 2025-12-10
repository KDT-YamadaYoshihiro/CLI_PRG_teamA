#pragma once
#include<vector>
#include<string>

#include"System/Math/Point/Point.hpp"
#include"Application/Map/TileCode.hpp"

//	長いので
using MapData = std::vector<std::vector<int>>;

namespace Game::MapSystem
{
	class Map
	{
	public:
		/// <summary>
		/// 移動可能かどうか
		/// </summary>
		/// <param name="Next">移動したい座標</param>
		/// <returns>true:</returns>
		bool CanMove(const Math::Point& Next)const noexcept;

		/// <summary>
		/// マップデータの取得
		/// </summary>
		/// <returns>データ</returns>
		const MapData& GetMapData();

	private:
		//	マップデータのコレクションを持つ
		MapData m_mapData;
	};
}
