#pragma once
#include<vector>
#include<string>

#include"System/Math/Point/Point.hpp"
#include"Application/Map/TileCode.hpp"

//	長いので
using MapData = std::vector<std::vector<int>>;
using MapDataString = std::vector<std::vector<std::string>>;

namespace Game::MapSystem
{
	class Map
	{
		/// <summary>
		/// マップの文字列変換
		/// </summary>
		void UpdateMapString();

	public:
		/// <summary>
		/// 移動可能かどうか
		/// </summary>
		/// <param name="Next">移動したい座標</param>
		/// <returns>true:</returns>
		bool CanMove(const Math::Point& Next)const noexcept;

		/// <summary>
		/// マップの状態更新
		/// </summary>
		/// <param name="Next"></param>
		void Update(const Math::Point& Next);

		/// <summary>
		/// マップデータのセット
		/// </summary>
		/// <param name="MapData"></param>
		void SetMapData(const std::vector<std::vector<int>>& MapData);

		/// <summary>
		/// マップデータを文字列に変換する
		/// </summary>
		/// <returns></returns>
		MapDataString GetMapString()const;

		/// <summary>
		/// マップデータの取得
		/// </summary>
		/// <returns>データ</returns>
		const MapData& GetMapData();

	private:
		/// <summary>
		/// マップデータのコレクション
		/// </summary>
		MapData m_mapData;

		/// <summary>
		/// マップデータを変換したコレクション
		/// </summary>
		MapDataString m_mapDataString;
	};
}
