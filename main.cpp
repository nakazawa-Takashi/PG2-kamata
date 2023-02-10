#include <Novice.h>
#include"Player.h"
#include"Enemy.h"
const char kWindowTitle[] = "LC1C_24_ナカザワタカシ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player = new Player;
	Enemy* enemy = new Enemy(100, 400);
	Enemy* enemy1 = new Enemy(600, 500);

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

		/*----------------ぷれーやー処理--------------------*/
		player->Move(keys, preKeys);
		player->BulletDistance(keys, preKeys, enemy->GetPosX(), enemy->GetPosY(), enemy->GetRadius(), enemy->GetAliv());
		player->BulletDistance(keys, preKeys, enemy1->GetPosX(), enemy1->GetPosY(), enemy1->GetRadius(), enemy1->GetAliv());

		/*-------------------てき処理----------------------*/
		enemy->Move();
		enemy->respawn(player->EnemyGetAliv());

		enemy1->Move();
		enemy1->respawn(player->EnemyGetAliv());

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		/*----------------ぷれーやー処理--------------------*/
		player->Draw();

		/*-------------------てき処理----------------------*/
		enemy->Draw();
		enemy1->Draw();
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