#include <Novice.h>
#include <stdio.h>
#include <stdlib.h>	
#include <cmath>
#include<time.h>
#include <corecrt_math_defines.h>
#define _USE_MATH_DEFINES

enum GameScene {
	SCENE_TITLE,
	SCENE_PLAY,
	SCENE_RESULT
};

struct Vector2 {
	float x;
	float y;
};

//aaaaa

const char kWindowTitle[] = "オキノ_生死_バイ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		int whiteTextureHandle = Novice::LoadTexture("./NoviceResources/white1x1.png");

		float rectPosX = 640.0f;
		float rectPosY = 1000.0f;
		float rectW = 100.0f;
		float rectH = 100.0f;

		// 左上
		float kLeftTopX = -rectW / 2.0f;
		float kLeftTopY = -rectH / 2.0f;
		// 右上
		float kRightTopX = rectW / 2.0f;
		float kRightTopY = -rectH / 2.0f;
		// 左下
		float kLeftBottomX = -rectW / 2.0f;
		float kLeftBottomY = rectH / 2.0f;
		// 右下
		float kRightBottomX = rectW / 2.0f;
		float kRightBottomY = rectH / 2.0f;


		// 左上
		float newLeftTopX = 0.0f;
		float newLeftTopY = 0.0f;
		// 右上
		float newRightTopX = 0.0f;
		float newRightTopY = 0.0f;
		// 左下
		float newLeftBottomX = 0.0f;
		float newLeftBottomY = 0.0f;
		// 右下
		float newRightBottomX = 0.0f;
		float newRightBottomY = 0.0f;

		// 左上
		float LeftTopPosX = rectPosX + kLeftTopX;
		float LeftTopPosY = rectPosY + kLeftTopY;
		// 右上
		float RightTopPosX = rectPosX + kRightTopX;
		float RightTopPosY = rectPosY + kRightTopY;
		// 左下
		float LeftBottomPosX = rectPosX + kLeftBottomX;
		float LeftBottomPosY = rectPosY + kLeftBottomY;
		// 右下
		float RightBottomPosX = rectPosX + kRightBottomX;
		float RightBottomPosY = rectPosY + kRightBottomY;


		static float theta = 0.0f;

		///
		/// ↓更新処理ここから
		///

		theta += (1.0f / 40.0f) * float(M_PI);

		// 左上
		newLeftTopX = kLeftTopX * cosf(theta) - kLeftTopY * sinf(theta);
		newLeftTopY = kLeftTopY * cosf(theta) + kLeftTopX * sinf(theta);
		// 右上
		newRightTopX = kRightTopX * cosf(theta) - kRightTopY * sinf(theta);
		newRightTopY = kRightTopY * cosf(theta) + kRightTopX * sinf(theta);
		// 左下
		newLeftBottomX = kLeftBottomX * cosf(theta) - kLeftBottomY * sinf(theta);
		newLeftBottomY = kLeftBottomY * cosf(theta) + kLeftBottomX * sinf(theta);
		// 右下
		newRightBottomX = kRightBottomX * cosf(theta) - kRightBottomY * sinf(theta);
		newRightBottomY = kRightBottomY * cosf(theta) + kRightBottomX * sinf(theta);

		//左上
		LeftTopPosX = rectPosX + newLeftTopX;
		LeftTopPosY = rectPosY + newLeftTopY;
		//右上
		RightTopPosX = rectPosX + newRightTopX;
		RightTopPosY = rectPosY + newRightTopY;
		//左下
		LeftBottomPosX = rectPosX + newLeftBottomX;
		LeftBottomPosY = rectPosY + newLeftBottomY;
		//右下
		RightBottomPosX = rectPosX + newRightBottomX;
		RightBottomPosY = rectPosY + newRightBottomY;


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::DrawQuad(
			static_cast<int>(LeftTopPosX),
			static_cast<int>(LeftTopPosY),
			static_cast<int>(RightTopPosX),
			static_cast<int>(RightTopPosY),
			static_cast<int>(LeftBottomPosX),
			static_cast<int>(LeftBottomPosY),
			static_cast<int>(RightBottomPosX),
			static_cast<int>(RightBottomPosY),
			0, 0,
			static_cast<int>(rectW), static_cast<int>(rectH),
			whiteTextureHandle,
			WHITE
		);

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
