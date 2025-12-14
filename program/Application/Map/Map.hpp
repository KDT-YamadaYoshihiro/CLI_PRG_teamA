#pragma once
#include<vector>
#include<string>

#include"System/Math/Point/Point.hpp"
#include"Application/Map/TileCode.hpp"

#include"System/Math/Point/Point.hpp"

//	長いので
using MapData = std::vector<std::vector<int>>;
using MapDataString = std::vector<std::vector<std::string>>;

namespace Game::MapSystem
{
	class Map
	{
	public:
		/// <summary>
		/// マップの文字列変換
		/// </summary>
		void UpdateMapString();

		/// <summary>
		/// マップの表示の追加
		/// </summary>
		void RenderMapString();


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

		std::vector<std::string> GetLines();

		/// <summary>
		/// プレイヤーと階段の位置が当たっているかどうか
		/// </summary>
		/// <param name="player"></param>
		/// <returns></returns>
		bool IsPlayerAtStairs(const Math::Point& player);

	private:
		/// <summary>
		/// マップデータのコレクション
		/// </summary>
		MapData m_mapData;

		/// <summary>
		/// マップデータを変換したコレクション
		/// </summary>
		MapDataString m_mapDataString;

		/// <summary>
		/// 表示するマップデータ
		/// </summary>
		std::vector<std::string> m_views;
	};
}
