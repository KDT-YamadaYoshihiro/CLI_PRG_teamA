#pragma once
#include "Scene/SceneBase.h"

class GameClearScene : public SceneBase
{
public:
	GameClearScene() = default;
	virtual ~GameClearScene() = default;

	//	‰Šú‰»
	void Initialize()override;

	// XV
	void Update() override;

	// •`‰æ
	void Render() override {};
};

