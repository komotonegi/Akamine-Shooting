#pragma once
#include"switchingScene.h"

class GameMain : public switchingScene {
private:
	int player;
	int enemy;
public:
	//デストラクタ
	virtual ~GameMain() {};

	//描画以外の更新
	virtual switchingScene* Update() override;

	//描画に関することの更新
	virtual void Draw() const override;

	//コンストラクタ
	GameMain();
	//メンバ関数の宣言
	//当たり判定

};