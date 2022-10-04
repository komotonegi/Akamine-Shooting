#pragma once

//デフォルトの抽象シーンクラス
//ユーザーはこれを継承してシーンを実装する
class switchingScene {
public:
	//デストラクタ
	virtual ~switchingScene() {};

	//描画以外の更新
	virtual switchingScene* Update() = 0;

	//描画に関することの更新
	virtual void Draw() const = 0;
};