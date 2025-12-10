#pragma once

// シーンの基底クラス
class SceneBase
{

public:
	virtual ~SceneBase() = default;

	// 初期化
	virtual void Initialize() {};

	// 更新
	virtual void Update() = 0;

	// 描画
	virtual void Render() = 0;

	// 終了()
	virtual void Release() {};

};