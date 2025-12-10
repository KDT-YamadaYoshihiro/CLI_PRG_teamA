#pragma once
#include "Scene/SceneBase.h"

class TestScene : public SceneBase
{
public:
	// ‰Šú‰»
	void Initialize() override;

	// XV
	void Update() override;

	// •`‰æ
	void Render() override;

	// I—¹()
	void Release() override;

};