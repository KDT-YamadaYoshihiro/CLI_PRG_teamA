#pragma once
#include <memory>
#include "../program/System/Utility/Singleton.hpp"
#include "SceneBase.h"

class SceneManager : public Singleton<SceneManager>{

private:

	friend class Singleton<SceneManager>;
	// Scene基底クラスのポインタ
	std::unique_ptr<SceneBase> m_currentScene;

public:

	// イニシャライズ
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Render();

	// 終了
	void Release();

	// シーン変更
	template<typename T>
	void ChangeScene();

};

template<typename T>
void SceneManager::ChangeScene()
{
	// 現在のシーンを解放して新しいシーンを作成
	if (m_currentScene)
	{
		m_currentScene->Release();
	}
	m_currentScene = std::make_unique<T>();
}