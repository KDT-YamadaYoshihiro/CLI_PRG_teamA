#pragma once
#include "../program/Scene/SceneBase.h"
#include "Application/State/enum/StateEnum.hpp"
#include "Application/Map/Map.hpp"
#include"Application/Charactor/Player/Player.hpp"

#include<memory>


class InGameScene : public SceneBase
{
	/// <summary>
	/// マップにプレイヤーを適応して表示する
	/// </summary>
	void RenderMapWithPlayer();
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

	/// <summary>
	/// プレイヤー
	/// </summary>
	std::unique_ptr<Chara::Player> m_player;

	/// <summary>
	/// 今のマップの番号
	/// </summary>
	int m_mapNum = 1;
};