#include"SceneManager.h"

switchingScene* SceneManager::Update() {
	switchingScene* s = Scene->Update();

	if (s != Scene) {
		delete Scene;
		Scene = s;
	}

	return s;
}

void SceneManager::Draw() const {
	Scene->Draw();
}