#include <iostream>
#include <stdlib.h>
#include "DefalutScene.h"


DefalutScene::DefalutScene()
{
}

DefalutScene::~DefalutScene()
{
	this->Release();
}

// 初期化
void DefalutScene::Initialize()
{
	std::cout << "DefalutScene Create()" << std::endl;
}

// 更新
void DefalutScene::Update()
{

}

// 描画
void DefalutScene::Render()
{
}

// 解放
void DefalutScene::Release()
{
	// コンソール画面のリセット
	std::system("cls");
}