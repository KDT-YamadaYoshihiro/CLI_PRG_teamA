#include "Graphics/View/View.hpp"
#include "System/Utility/Define.hpp"

/// <summary>
/// 今のハンドル取得
/// </summary>
/// <returns></returns>
HANDLE Graphics::View::GetBackBufferHandle() const
{
	return m_sceneBuffer[1 - m_currentBuffer];
}

/// <summary>
/// 初期化
/// </summary>
/// <returns>true:成功</returns>
bool Graphics::View::Initialize()
{
	//	メインバッファ
	m_sceneBuffer[FRONT_BUFFER_INDEX] = GetStdHandle(STD_OUTPUT_HANDLE);
	m_sceneBuffer[BACK_BUFFER_INDEX] = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);

	if (m_sceneBuffer[BACK_BUFFER_INDEX] == INVALID_HANDLE_VALUE)
	{
		DEBUG_BREAK
		return false;
	}

	//	最初の表示
	SetConsoleActiveScreenBuffer(m_sceneBuffer[m_currentBuffer]);

	return true;
}

/// <summary>
/// バッファの切り替え
/// </summary>
void Graphics::View::Flip()
{
	SetConsoleActiveScreenBuffer(m_sceneBuffer[m_currentBuffer]);

	//	バッファの切り替え
	m_currentBuffer = 1 - m_currentBuffer;
}

void Graphics::View::ClearBuffer()
{

	HANDLE back = this->GetBackBufferHandle();

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(back, &csbi);

	DWORD cellCnt = csbi.dwSize.X * csbi.dwSize.Y;
	DWORD count;

	FillConsoleOutputCharacter(back, ' ', cellCnt, { 0,0 }, &count);
	FillConsoleOutputAttribute(back, csbi.wAttributes, cellCnt, { 0,0 }, &count);
}

/// <summary>
/// 表示する文字列のクリア
/// </summary>
void Graphics::View::AllClear()
{
	m_views.clear();
}

/// <summary>
/// 生成時の処理
/// </summary>
void Graphics::View::OnCreate()
{
	m_currentBuffer = 0;
	this->Initialize();
}

/// <summary>
/// 表示する文字列の追加
/// </summary>
/// <param name="str"></param>
void Graphics::View::AddString(const std::filesystem::path& str)
{
	m_views.push_back(str);
}

/// <summary>
/// 表示
/// </summary>
void Graphics::View::Render()
{
	HANDLE back = this->GetBackBufferHandle();
	DWORD written;

	SHORT y = 0;
	for (auto& view : m_views)
	{
		WriteConsoleOutputCharacter(
			back,
			view.wstring().c_str(),
			(DWORD)view.wstring().size(),
			COORD{ 0, y },
			&written
		);
		y++;
	}
	//m_views.clear();

}


