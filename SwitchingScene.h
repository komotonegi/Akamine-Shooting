#pragma once

//�f�t�H���g�̒��ۃV�[���N���X
//���[�U�[�͂�����p�����ăV�[������������
class switchingScene {
public:
	//�f�X�g���N�^
	virtual ~switchingScene() {};

	//�`��ȊO�̍X�V
	virtual switchingScene* Update() = 0;

	//�`��Ɋւ��邱�Ƃ̍X�V
	virtual void Draw() const = 0;
};