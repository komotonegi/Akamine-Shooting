/********************************************************************
**	  PG2 2-4 
**	　シューティングゲームの作成(2022)
********************************************************************/
#include "DxLib.h"

//シーンマネージャー
#include"SceneManager.h"

/***********************************************
 * 変数の宣言
 ***********************************************/
int	g_OldKey;				// 前回の入力キー
int	g_NowKey;				// 今回の入力キー
int	g_KeyFlg;				// 入力キー情報

 /***********************************************
  * プログラムの開始
  ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) {

    // タイトルを test に変更
    SetMainWindowText("シューティングゲーム");

    ChangeWindowMode(TRUE);		// ウィンドウモードで起動

    if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

    //ブロック画像データの読み込み
    //if (LoadDivGraph("images/Block.bmp", 8, 8, 1, 40, 8, g_BlockImage) == -1) return -1;

    //ランキング画像データの読み込み
    //if ((g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1) return -1;

    //if (ranking.ReadRanking() == -1)  return  -1;    //ランキングデータの読み込み

    SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

    SetFontSize(20);		// 文字サイズを設定

    //最初に入れるシーンを決める
    SceneManager sceneMng(/*new Title()*/);

    // ゲームループ
    while (ProcessMessage() == 0 && sceneMng.Update() != nullptr) {

        // 入力キー取得
        g_OldKey = g_NowKey;
        g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
        g_KeyFlg = g_NowKey & ~g_OldKey;

        ClearDrawScreen();		// 画面の初期化

        sceneMng.Draw();

        ScreenFlip();			// 裏画面の内容を表画面に反映

    }

    DxLib_End();	// DXライブラリ使用の終了処理

    return 0;	// ソフトの終了
}