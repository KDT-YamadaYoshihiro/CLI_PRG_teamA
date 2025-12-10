#include "Graphics/View/View.hpp"
#include "System/Utility/Define.hpp"

// 1:Window Console Api 2: std::cout
#define RENDER_MODE 2

#if RENDER_MODE == 2
#include<iostream>
#endif // RENDER_MODE == 1


/// <summary>
/// èâä˙âª
/// </summary>
/// <returns>true:ê¨å˜</returns>
bool Graphics::View::Initialize()
{
#if RENDER_MODE == 1
	m_console = GetStdHandle(STD_OUTPUT_HANDLE);
#elif RENDER_MODE == 2
	m_views.clear();		
#endif // RENDER_MODE == 1

	isDirty = true;
	return true;
}

/// <summary>
/// ê∂ê¨éûÇÃèàóù
/// </summary>
void Graphics::View::OnCreate()
{
	this->Initialize();
}

/// <summary>
/// ï\é¶Ç∑ÇÈï∂éöóÒÇÃí«â¡
/// </summary>
/// <param name="str"></param>
void Graphics::View::AddLine(const std::string& str)
{
	m_views.push_back(str);
	isDirty = true;
}

/// <summary>
/// ï\é¶Ç∑ÇÈï∂éöóÒÇÃçÌèú
/// </summary>
void Graphics::View::ClearLines()
{
	m_views.clear();
	isDirty = true;
}

/// <summary>
/// âÊñ ÇÇ∑Ç◊Çƒè¡Ç∑
/// </summary>
void Graphics::View::ClearScene()
{
#if RENDER_MODE == 1

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(m_console, &csbi);

	DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;
	DWORD written;

	COORD home = { 0, 0 };

	FillConsoleOutputCharacterA(m_console, ' ', cellCount, home, &written);
	FillConsoleOutputAttribute(m_console, csbi.wAttributes, cellCount, home, &written);

	SetConsoleCursorPosition(m_console, home);
#elif RENDER_MODE == 2
	system("cls");
#endif // RENDER_MODE == 1
}

/// <summary>
/// ï\é¶
/// </summary>
void Graphics::View::Render()
{
	if (isDirty == false)
	{
		return;
	}

	this->ClearScene();

#if RENDER_MODE == 1
	COORD pos = { 0,0 };
	DWORD written;
	for (const auto& line : m_views)
	{
		pos.X = 0;
		SetConsoleCursorPosition(m_console, pos);
		WriteConsoleA(
			m_console,
			line.c_str(),
			(DWORD)line.size(),
			&written,
			nullptr
		);
		pos.Y++;
	}
#elif RENDER_MODE == 2
	for (const auto& line : m_views)
	{
		std::cout << line << std::endl;
	}

#endif // RENDER_MODE == 1

	isDirty = false;
}


