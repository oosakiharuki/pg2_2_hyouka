#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "LC1B_03_オオサキ_ハルキ_タイトル";

enum GameSeen {
	Title,
	Game,
	Clear,
	GameOver
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player;
	Enemy* enemy = new Enemy;

	bool isMissFlag = false;
	bool RespawnFlag = false;
	int timer[2] = { 50,50 };

	int Hp = 10;
	
	int EnemyBulletX;
	int EnemyBulletY;
	int distEB;
	int radiusEB;

	int EnemyPlayerX;
	int EnemyPlayerY;
	int distEP;
	int radiusEP;

	GameSeen seen = Title;

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

		switch (seen)
		{
		case Title:
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				seen = Game;
			}
			break;
		case Game:
			player->Update(keys, preKeys);
			enemy->Update();

			EnemyPlayerX = enemy->GetPosX() - player->GetPosX();
			EnemyPlayerY = enemy->GetPosY() - player->GetPosY();
			distEP = (EnemyPlayerX * EnemyPlayerX) + (EnemyPlayerY * EnemyPlayerY);
			radiusEP = enemy->GetRadius() + player->GetRadius();
			
			if (distEP <= radiusEP * radiusEP) {
				player->Death();
				isMissFlag = true;
			}
			if (isMissFlag ==true){
				timer[0]--;
			}
			if (timer[0] < 0) {
				seen = GameOver;
				timer[0] = 50;
				isMissFlag = false;
			}

			EnemyBulletX = enemy->GetPosX() - player->bullet->GetPosX();
			EnemyBulletY = enemy->GetPosY() - player->bullet->GetPosY();
			distEB = (EnemyBulletX * EnemyBulletX) + (EnemyBulletY * EnemyBulletY);
			radiusEB = enemy->GetRadius() + player->bullet->GetRadius();

			if (distEB <= radiusEB * radiusEB) {
				enemy->Death();
				RespawnFlag = true;
			}

			if (RespawnFlag == true) {
				timer[1]--;
			}
			if (timer[1] < 0) {
				Hp--;
				enemy->Respawn();
				RespawnFlag = false;
				timer[1] = 50;
			}
			if (Hp == 0) {
				seen = Clear;
			}
			break;
		case Clear:
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				seen = Title;
				Hp = 10;
			}
			break;
		case GameOver:
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				seen = Game;
				player->Respawn();
			}
			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (seen)
		{
		case Title:
			Novice::ScreenPrintf(100, 20, "SHOOTING GAMR");
			Novice::ScreenPrintf(120, 60, "START SPACE");
			break;
		case Game:
			player->Draw();
			enemy->Draw();
			Novice::ScreenPrintf(100, 20, "Hp %d", Hp);
			break;
		case Clear:
			Novice::ScreenPrintf(100, 20, "STAGE CLEAR");
			Novice::ScreenPrintf(120, 60, "SPACE TITLE");
			break;
		case GameOver:
			Novice::ScreenPrintf(100, 20, "GAME OVER");
			Novice::ScreenPrintf(120, 60, "SPACE CONTINUE");
			break;
		}
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
