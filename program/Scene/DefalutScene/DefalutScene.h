#pragma once
#include "../program/Scene/SceneBase.h"


class DefalutScene : public SceneBase
{

public:

	// コンストラクタ・デストラクタ
	DefalutScene();
	virtual ~DefalutScene();

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

