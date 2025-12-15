#include "CharactorBase.hpp"


/// <summary>
/// ステータス
/// </summary>
/// <returns></returns>
std::string Chara::CharaBase::GetStatusString()
{
    std::string view;
    view = m_status.Name + ":" + std::to_string(m_status.HP) + "/"
        + std::to_string(m_status.MaxHP);
    return view;
}
