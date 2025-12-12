#pragma once
#include "../program/Scene/SceneBase.h"
#include "Application/State/enum/StateEnum.hpp"
#include "Application/Map/Map.hpp"


class InGameScene : public SceneBase
{
public:
	// コンストラクタ・デストラクタ
	InGameScene();
	virtual ~InGameScene();

	// SceneBaseの仮想関数をオーバーライド
	// 初期化
	void Initialize() override;
	// 更新
	void Update() override;
	// 描画
	void Render() override;
	// 解放
	void Release() override;
private:
	/// <summary>
	/// InGameの状態：最初はFieldから
	/// </summary>
	Game::GameState m_state = Game::GameState::Field;

	/// <summary>
	/// マップ関係
	/// </summary>
	Game::MapSystem::Map m_map;
};