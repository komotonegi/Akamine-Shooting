#pragma once
#include"switchingScene.h"

class GameMain : public switchingScene {
private:
	int player;
	int enemy;
public:
	//�f�X�g���N�^
	virtual ~GameMain() {};

	//�`��ȊO�̍X�V
	virtual switchingScene* Update() override;

	//�`��Ɋւ��邱�Ƃ̍X�V
	virtual void Draw() const override;

	//�R���X�g���N�^
	GameMain();
	//�����o�֐��̐錾
	//�����蔻��

};