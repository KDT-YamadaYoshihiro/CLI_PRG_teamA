#include "Map.hpp"

/// <summary>
/// 移動可能かどうか
/// </summary>
/// <param name="Next">移動したい座標</param>
/// <returns>true:</returns>
bool Game::MapSystem::Map::CanMove(const Math::Point& Next) const noexcept
{
    //  データがないとき判定もくそもない
    if (m_mapData.empty() == true)
    {
        return false;
    }

    //  移動先がマップ外ならfalse
    if (Next.x < 0 || Next.y < 0 || Next.x >= m_mapData[0].size() || Next.y >= m_mapData.size())
    {
        return false;
    }

    //  移動したい場所が移動可能かどうか



    return true;
}

/// <summary>
/// マップデータの取得
/// </summary>
/// <returns>データ</returns>
const MapData& Game::MapSystem::Map::GetMapData()
{
    return m_mapData;
}
