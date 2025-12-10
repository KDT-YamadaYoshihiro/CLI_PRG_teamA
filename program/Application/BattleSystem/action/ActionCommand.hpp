#pragma once

#include<span>
#include<string>
#include"Application/Inventory/Item/base/Item.hpp";

namespace Battle
{

/// <summary>
/// プレイヤーの行動コマンド
/// </summary>
enum class ePlayerCommand : int
{
	Attack = 1,
	Magic,
	Item,
};

/// <summary>
/// アクションでの入力結果
/// </summary>
struct ActionResult
{
	//	選択種別
	ePlayerCommand command = ePlayerCommand::Attack;
	//	選択された番号（通常攻撃では使用しない）
	int selectID = -1;
};


/// <summary>
/// アクションの選択
/// </summary>
class ActionSelector
{
public:
	/// <summary>
	/// コマンドの選択
	/// </summary>
	/// <returns></returns>
	static ActionResult SelectCommand(std::span<const std::string> MagicNames, std::span<const std::string> ItemNames);

private:
	/// <summary>
	///	魔法の選択
	/// </summary>
	/// <returns></returns>
	static ActionResult SelectMagic(std::span<const std::string> MagicNames);

	/// <summary>
	/// アイテムの選択
	/// </summary>
	/// <returns></returns>
	static ActionResult SelectItem(std::span<const std::string> ItemNames);

	/// <summary>
	/// 選択をしたかどうか
	/// </summary>
	/// <returns></returns>
	static bool IsSelected(const ActionResult& action);
};

	
}
