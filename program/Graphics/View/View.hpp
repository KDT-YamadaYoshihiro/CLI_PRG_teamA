#pragma once
#include<filesystem>
#include<vector>
#include<array>
#include<Windows.h>

#include "System/Utility/Singleton.hpp"


namespace Graphics
{
	class View : public Singleton<View>
	{
		GENERATE_SINGLETON_BODY(View)

		static constexpr UINT FRONT_BUFFER_INDEX = 0;
		static constexpr UINT BACK_BUFFER_INDEX = 1;
		static constexpr UINT CONSOLE_BUFFER_MAX = 2;

		/// <summary>
		/// 今のハンドル取得
		/// </summary>
		/// <returns></returns>
		HANDLE GetBackBufferHandle() const;

	public:
		/// <summary>
		/// 初期化
		/// </summary>
		/// <returns>true:成功</returns>
		bool Initialize();

		/// <summary>
		/// バッファの切り替え
		/// </summary>
		void Flip();

		/// <summary>
		/// バッファのクリア
		/// </summary>
		void ClearBuffer();

		/// <summary>
		/// 表示する文字列のクリア
		/// </summary>
		void AllClear();

		/// <summary>
		/// 生成時の処理
		/// </summary>
		void OnCreate()override;

		/// <summary>
		/// 表示する文字列の追加
		/// </summary>
		/// <param name="str"></param>
		void AddString(const std::filesystem::path& str);

		/// <summary>
		/// 表示
		/// </summary>
		void Render();
	private:

		/// <summary>
		/// 画面のバッファ数
		///	</summary>
		std::array<HANDLE, CONSOLE_BUFFER_MAX> m_sceneBuffer;

		/// <summary>
		/// 表示する文字列のコレクション
		/// </summary>
		std::vector<std::filesystem::path> m_views;

		/// <summary>
		/// 今の表バッファのインデックス
		/// </summary>
		UINT m_currentBuffer = 0;
	};
}