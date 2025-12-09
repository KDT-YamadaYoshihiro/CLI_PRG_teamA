#pragma once

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

	private:
		int m_sleepMilSeconds;
	};
}
