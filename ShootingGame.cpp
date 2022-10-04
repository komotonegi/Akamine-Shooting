/********************************************************************
**	  PG2 2-4 
**	�@�V���[�e�B���O�Q�[���̍쐬(2022)
********************************************************************/
#include "DxLib.h"

//�V�[���}�l�[�W���[
#include"SceneManager.h"

/***********************************************
 * �ϐ��̐錾
 ***********************************************/
int	g_OldKey;				// �O��̓��̓L�[
int	g_NowKey;				// ����̓��̓L�[
int	g_KeyFlg;				// ���̓L�[���

 /***********************************************
  * �v���O�����̊J�n
  ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) {

    // �^�C�g���� test �ɕύX
    SetMainWindowText("�V���[�e�B���O�Q�[��");

    ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

    if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

    //�u���b�N�摜�f�[�^�̓ǂݍ���
    //if (LoadDivGraph("images/Block.bmp", 8, 8, 1, 40, 8, g_BlockImage) == -1) return -1;

    //�����L���O�摜�f�[�^�̓ǂݍ���
    //if ((g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1) return -1;

    //if (ranking.ReadRanking() == -1)  return  -1;    //�����L���O�f�[�^�̓ǂݍ���

    SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

    SetFontSize(20);		// �����T�C�Y��ݒ�

    //�ŏ��ɓ����V�[�������߂�
    SceneManager sceneMng(/*new Title()*/);

    // �Q�[�����[�v
    while (ProcessMessage() == 0 && sceneMng.Update() != nullptr) {

        // ���̓L�[�擾
        g_OldKey = g_NowKey;
        g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
        g_KeyFlg = g_NowKey & ~g_OldKey;

        ClearDrawScreen();		// ��ʂ̏�����

        sceneMng.Draw();

        ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f

    }

    DxLib_End();	// DX���C�u�����g�p�̏I������

    return 0;	// �\�t�g�̏I��
}