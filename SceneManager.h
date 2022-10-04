#pragma once

#include"switchingScene.h"

//シーンマネージャークラス
//各シーンの切り替えを管理
class SceneManager : public switchingScene {
private:
	switchingScene* Scene; //現在のシーン
public:
	// コンストラクタ
	SceneManager(switchingScene* scene) : Scene(scene) { }

	// デストラクタ
	~SceneManager() {
		delete Scene;
	}

	//描画以外の更新の実装
	switchingScene* Update() override;

	//描画に関する事の実装
	void Draw()const override;
};