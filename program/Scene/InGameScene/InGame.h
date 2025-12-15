#pragma once
#include "../program/Scene/SceneBase.h"
#include "Application/State/enum/StateEnum.hpp"
#include "Application/Map/Map.hpp"
#include"Application/Charactor/Player/Player.hpp"
#include "Application/Charactor/Enemy/Enemy.h"
#include "Application/BattleSystem/Encount/EncountSystem.h"
#include "Application/Inventory/Inventory/InventoryManager.hpp"

#include<memory>
#include<vector>


class InGameScene : public SceneBase
{
	/// <summary>
	/// マップにプレイヤーを適応して表示する
	/// </summary>
	void RenderMapWithPlayer();

	/// <summary>
	/// マップの表示
	/// </summary>
	void RenderMap();

	/// <summary>
	/// 階層の更新と再読み込み
	/// </summary>
	void MoveToNextFloor();

	/// <summary>
	/// 敵の生成
	/// </summary>
	void CreateEnemy();

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
	/// 敵のコレクション
	/// </summary>
	std::vector<std::unique_ptr<Chara::Enemy>> m_enemys;

	/// <summary>
	/// エンカウントを管理するクラス
	/// </summary>
	EncountSystem encount;



	/// <summary>
	/// 今のマップの番号
	/// </summary>
	int m_mapNum = 1;

	const int STATE_MAX = 2;
};