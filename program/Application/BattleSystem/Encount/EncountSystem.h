#pragma once
#include "../../../System/Utility/Random.hpp"

// エンカウントシステム
class EncountSystem
{
private:

	// エンカウント率
	float m_encountRate = 0.1; 

public:
	// エンカウント判定
	// encountRate: エンカウント率 (0.0 ~ 1.0)
	bool IsEncount()
	{
		// パターン１　常にエンカウントの確率は固定

		// float roll = Random::Range(0.0f, 1.0f);

		// return roll < m_encountRate;

		// パターン２　何か行動するたびにエンカウント確率は増えていく

		float roll2 = Random::Range(0.0f, 1.0f);

		// エンカウント率を増加させる
		m_encountRate += 0.05f; 

		if (roll2 < m_encountRate)
		{
			// エンカウントしたらエンカウント率をリセット
			m_encountRate = 0.1f; 
			return true;
		}

		return false;
	}
};
