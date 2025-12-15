#pragma once
#include "../program/Scene/SceneBase.h"
#include "../../Engine/Engine.hpp"

class GameClearScene : public SceneBase
{
	public:
	// コンストラクタ・デストラクタ
	GameClearScene();
	virtual ~GameClearScene();
	Engine::Engine* engine = Engine::Engine::GetInstance();
	// SceneBaseの仮想関数をオーバーライド
	// 初期化
	void Initialize() override;
	// 更新
	void Update() override;
	// 描画
	void Render() override;
	// 解放
	void Release() override;
};
