#pragma once

// シーンの基底クラス
class SceneBase
{

public:

	// イニシャライズ
	virtual void Initialize() = 0;

	// 更新
	virtual void Update() = 0;

	// 描画
	virtual void Render() = 0;

	// 終了()
	virtual void Release() = 0;

};