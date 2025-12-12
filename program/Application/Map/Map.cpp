#include "Map.hpp"

#include "Graphics/View/View.hpp"

/// <summary>
/// マップの文字列変換
/// </summary>
void Game::MapSystem::Map::UpdateMapString()
{
    //  初期状態に戻す
    const int Height = m_mapData.size();
    const int Width = m_mapData[0].size();
    m_views.clear();
    m_views.resize(Height);

    for (int h = 0; h < Height; h++)
    {
        for (int w = 0; w < Width; w++)
        {
            int value = m_mapData[h][w];
            switch (value)
            {
            case static_cast<int>(Game::MapSystem::TileType::Load):
                m_views[h] += "+";
                break;
            case static_cast<int>(Game::MapSystem::TileType::Stairm):
                m_views[h] += "@";
                break;
            case static_cast<int>(Game::MapSystem::TileType::Wall):
                m_views[h] += "=";
                break;
            default:
                m_views[h] += "？";
                break;
            }

        }
    }
}

void Game::MapSystem::Map::RenderMapString()
{
    
}

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
    if (m_mapData[Next.y][Next.x] == static_cast<int>(TileType::Wall))
    {
        return false;
    }

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

std::vector<std::string> Game::MapSystem::Map::GetLines()
{
    return m_views;
}

/// <summary>
/// マップの状態更新
/// </summary>
/// <param name="Next"></param>
void Game::MapSystem::Map::Update(const Math::Point& Next)
{
    //  
    if (this->CanMove(Next) == false)
    {
        return;
    }


}

/// <summary>
/// マップデータのセット
/// </summary>
/// <param name="MapData"></param>
void Game::MapSystem::Map::SetMapData(const std::vector<std::vector<int>>& MapData)
{
    m_mapData = MapData;
}

/// <summary>
/// マップデータを文字列に変換する
/// </summary>
/// <returns></returns>
MapDataString Game::MapSystem::Map::GetMapString() const
{
    return m_mapDataString;
}
