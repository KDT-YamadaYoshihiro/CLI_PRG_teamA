#include <iostream>
#include <stdlib.h>
#include "Title.h"

// コンストラクタ・デストラクタ
TitleScene::TitleScene()
{
}
TitleScene::~TitleScene()
{
	this->Release();
}

// 初期化
void TitleScene::Initialize()
{
	std::cout << "TitleScene Create()" << std::endl;
}

// 更新
void TitleScene::Update()
{
}

// 描画
void TitleScene::Render()
{
}

// 解放
void TitleScene::Release()
{
	// コンソール画面のリセット
	std::system("cls");
}