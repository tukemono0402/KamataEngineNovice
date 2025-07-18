#include <Novice.h>
#include <corecrt_math.h>

const char kWindowTitle[] = "GC1C_10_トミグチカオル_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//円1の中心座標
	int pos1X = 50;     //円1のX座標
	int pos1Y = 50;     //円1の Y座標
	int radius1 = 50;   //円1の半径

	//円2の中心座標
	int pos2X = 400;    //円2のX座標
	int pos2Y = 400;    //円2のY座標
	int radius2 = 100;      //円2の半径

	int Color = ;          //赤色

	int speed = 10;     //speedの速度
	double extent1 = pos2X - pos1X;   //  Xの範囲
	double extent2 = pos2Y - pos1Y;   //  Yの範囲
	float distance = static_cast<float>(extent1 * extent1 + extent2 * extent2);




	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		
		
		

		///
		/// ↓更新処理ここから
		///
		/// 
	

		if (keys[DIK_D]) {
			pos1X = pos1X + speed;     //　Dを押すと右(X+1)に移動   
		}

		if (keys[DIK_A]) {
			pos1X = pos1X - speed;     //  Aを押すと左(X-1)に移動
		}

		if (keys[DIK_W]) {
			pos1Y = pos1Y - speed;     //  Wを押すと上(Y+1)に移動
		}

		if (keys[DIK_S]) {
			pos1Y = pos1Y + speed;     //  Sを押すと上(Y-1)に移動
		}
		
		
		


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		

		Novice::DrawEllipse(pos2X, pos2Y, radius2, radius2, 0.0f, WHITE, kFillModeSolid);  //

		Novice::DrawEllipse(pos1X, pos1Y, radius1, radius1, 0.0f, Color, kFillModeSolid);  //






		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
