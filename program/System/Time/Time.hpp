#pragma once
#include <chrono>

namespace Engine
{
	class Time
	{
	public:
		Time();
		virtual ~Time() = default;

		/// <summary>
		/// デバイスコンテキストに関連づけられているディスプレイのHz取得
		/// </summary>
		/// <returns></returns>
		static int GetMonitorRefreshRate();

		/// <summary>
		/// DCのHzを取得してその時間分ウェイトをかける
		/// 疑似的なV-Syncなので精度はお察し
		/// </summary>
		void Wait();

		/// <summary>
		/// 時間を止める
		/// </summary>
		static void Sleep(std::chrono::seconds second);
		static void Sleep(std::chrono::milliseconds mil);

	private:
		int m_sleepMilSeconds;
	};
}
