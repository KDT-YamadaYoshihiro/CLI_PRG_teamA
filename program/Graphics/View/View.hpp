#pragma once
#include<filesystem>
#include<vector>
#include<array>
#include<Windows.h>
#include <string>

#include "System/Utility/Singleton.hpp"



namespace Graphics
{
	class View : public Singleton<View>
	{
		GENERATE_SINGLETON_BODY(View)

	public:
		/// <summary>
		/// 初期化
		/// </summary>
		/// <returns>true:成功</returns>
		bool Initialize();

		/// <summary>
		/// 生成時の処理
		/// </summary>
		void OnCreate()override;

		/// <summary>
		/// 表示する文字列の追加
		/// </summary>
		/// <param name="str"></param>
		void AddLine(const std::string& str);

		/// <summary>
		/// 表示する文字列の削除
		/// </summary>
		void ClearLines();

		/// <summary>
		/// 画面をすべて消す
		/// </summary>
		void ClearScene();

		/// <summary>
		/// 表示
		/// </summary>
		void Render();
	private:

		/// <summary>
		/// コンソールのハンドル
		/// </summary>
		HANDLE m_console;

		/// <summary>
		/// 表示する文字列のコレクション
		/// </summary>
		std::vector<std::string> m_views;

		/// <summary>
		/// true:コレクションの内容を表示する
		/// </summary>
		bool isDirty = true;
	};
}