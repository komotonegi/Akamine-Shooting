#pragma once

#include"switchingScene.h"

//�V�[���}�l�[�W���[�N���X
//�e�V�[���̐؂�ւ����Ǘ�
class SceneManager : public switchingScene {
private:
	switchingScene* Scene; //���݂̃V�[��
public:
	// �R���X�g���N�^
	SceneManager(switchingScene* scene) : Scene(scene) { }

	// �f�X�g���N�^
	~SceneManager() {
		delete Scene;
	}

	//�`��ȊO�̍X�V�̎���
	switchingScene* Update() override;

	//�`��Ɋւ��鎖�̎���
	void Draw()const override;
};