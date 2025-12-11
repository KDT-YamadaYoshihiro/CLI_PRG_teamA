#pragma once
#include "../program/Scene/SceneBase.h"

class TitleScene : public SceneBase
{
public:
	// コンストラクタ・デストラクタ
	TitleScene();
	virtual ~TitleScene();

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