#include "System/Time/Time.hpp"
#include<Windows.h>


Engine::Time::Time()
	:m_sleepMilSeconds(16)
{
}

/// <summary>
/// デバイスコンテキストに関連づけられているディスプレイのHz取得
/// </summary>
/// <returns></returns>
int Engine::Time::GetMonitorRefreshRate()
{
	HDC hdc = GetDC(NULL);
	if (hdc == NULL)
	{
		return 0;
	}

	int RefreshRate = GetDeviceCaps(hdc, VREFRESH);
	ReleaseDC(NULL, hdc);

	if (RefreshRate <= 0)
	{
		return 60;
	}
	return RefreshRate;
}

/// <summary>
/// DCのHzを取得してその時間分ウェイトをかける
/// 疑似的なV-Syncなので精度はお察し
/// </summary>
void Engine::Time::Wait()
{
	m_sleepMilSeconds = 1000 / GetMonitorRefreshRate();
	Sleep(m_sleepMilSeconds);
}