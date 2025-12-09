#include "Application/Player/action/ActionCommand.hpp"
#include "Engine/Engine.hpp"
#include "System/Input/Key.hpp"

#include<iostream>


/// <summary>
/// コマンドの選択
/// </summary>
/// <returns></returns>
Battle::ActionResult Battle::ActionSelector::SelectCommand(std::span<const std::string> MagicNames, std::span<const std::string> ItemNames)
{
	//	選択するまで無限ループ
	while (true)
	{
		//	選択項目の追加
		CLI_ENGINE->GetView()->AddString("-----------------");
		CLI_ENGINE->GetView()->AddString("1: 攻撃");
		CLI_ENGINE->GetView()->AddString("2: 魔法");
		CLI_ENGINE->GetView()->AddString("3: アイテム");
		CLI_ENGINE->GetView()->AddString("選択してください");

		int input;
		std::cin >> input;

		//	何か文字があるとき
		if (std::cin.fail() == false)
		{
			ActionResult select;

			//	入力された数字によって処理分岐
			switch (input)
			{
				//	攻撃
			case static_cast<int>(ePlayerCommand::Attack):
				return ActionResult(ePlayerCommand::Attack,-1);

				//	魔法
			case static_cast<int>(ePlayerCommand::Magic):
				select = SelectMagic(MagicNames);
				//	選択されていたら情報を返す
				if (IsSelected(select) == true)
				{
					return select;
				}
				//	未選択、または戻るでここに抜ける
				break;

				//	アイテム
			case static_cast<int>(ePlayerCommand::Item):
				select = SelectItem(ItemNames);
				if (IsSelected(select) == true)
				{
					return select;
				}
				break;

			default:
				break;
			}
		}	// if cin.fill

		std::cin.clear();
		std::cin.ignore(1024, '\n');

		CLI_ENGINE->GetView()->AddString("無効な入力です");


	}	//	while
}

/// <summary>
///	魔法の選択
/// </summary>
/// <returns></returns>
Battle::ActionResult Battle::ActionSelector::SelectMagic(std::span<const std::string> MagicNames)
{
	//	選択するまで無限ループ
	while (true)
	{
		CLI_ENGINE->GetView()->AddString("------魔法一覧------");
		for (size_t id = 0; id < MagicNames.size(); id++)
		{
			//	IDと魔法名を表示
			CLI_ENGINE->GetView()->AddString(std::to_string(id) + ": " + MagicNames[id]);
		}

		CLI_ENGINE->GetView()->AddString("番号を入力してください");

		if (_kbhit())
		{
			int key = getch();
			if (key == static_cast<int>(Input::KeyCode::Escape))
			{
				return ActionResult(ePlayerCommand::Magic, -1);
			}
		}

		//	数値が欲しいのでstd::cinを使います
		int id = -1;
		std::cin >> id;
		if (std::cin.fail() == false && id >= 0 && id < static_cast<int>(MagicNames.size()))
		{
			return ActionResult(ePlayerCommand::Magic,id);
		}

		std::cin.clear();
		std::cin.ignore(1024, '\n');
		CLI_ENGINE->GetView()->AddString("無効な入力です");
	}
}

/// <summary>
/// アイテムの選択
/// </summary>
/// <returns></returns>
Battle::ActionResult Battle::ActionSelector::SelectItem(std::span<const std::string> ItemNames)
{
	//	選択するまで無限ループ
	while (true)
	{
		CLI_ENGINE->GetView()->AddString("------魔法一覧------");
		for (size_t id = 0; id < ItemNames.size(); id++)
		{
			//	IDと魔法名を表示
			CLI_ENGINE->GetView()->AddString(std::to_string(id) + ": " + ItemNames[id]);
		}

		CLI_ENGINE->GetView()->AddString("番号を入力してください");

		if (_kbhit())
		{
			int key = getch();
			if (key == static_cast<int>(Input::KeyCode::Escape))
			{
				return ActionResult(ePlayerCommand::Magic, -1);
			}
		}

		//	数値が欲しいのでstd::cinを使います
		int id = -1;
		std::cin >> id;
		if (std::cin.fail() == false && id >= 0 && id < static_cast<int>(ItemNames.size()))
		{
			return ActionResult(ePlayerCommand::Magic, id);
		}

		std::cin.clear();
		std::cin.ignore(1024, '\n');
		CLI_ENGINE->GetView()->AddString("無効な入力です");
	}
}

/// <summary>
/// 選択をしたかどうか
/// </summary>
/// <returns>true:選択済み</returns>
bool Battle::ActionSelector::IsSelected(const ActionResult& action)
{
	return action.selectID != -1;
}
