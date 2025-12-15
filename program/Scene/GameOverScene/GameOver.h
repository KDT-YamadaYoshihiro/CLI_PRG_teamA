#pragma once
#include "../program/Scene/SceneBase.h"
#include "../../Engine/Engine.hpp"

class GameOverScene : public SceneBase
{
	public:
	// コンストラクタ・デストラクタ
	GameOverScene();
	virtual ~GameOverScene();
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