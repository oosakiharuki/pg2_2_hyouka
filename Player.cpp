#include "Player.h"

Player::Player() {
	pos = { 400,500 };
	speed = 8;
	radius = 30;
}
Player::~Player() {
	delete bullet;
}
void Player::Update(char* keys, char* preKeys) {
	if (LifeFlag == true) {
		if (keys[DIK_W]) {
			pos.y -= speed;
		}
		if (keys[DIK_S]) {
			pos.y += speed;
		}
		if (keys[DIK_A]) {
			pos.x -= speed;
		}
		if (keys[DIK_D]) {
			pos.x += speed;
		}

		if (pos.y < 0 + radius / 2) {
			pos.y += speed;
		}
		if (pos.y > 720 - radius / 2) {
			pos.y -= speed;
		}
		if (pos.x < 0 + radius / 2) {
			pos.x += speed;
		}
		if (pos.x > 1280 - radius / 2) {
			pos.x -= speed;
		}

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && bullet->GetShotFlag() == false) {
			bullet->BulletFlag(pos.x, pos.y);
		}
		bullet->Update();
	}
}

void Player::Death() {
	LifeFlag = false;
}

void Player::Respawn() {
	LifeFlag = true;
}

void Player::Draw() {
	if (LifeFlag == true){
		Novice::DrawEllipse(pos.x, pos.y, radius, radius, 0.0f, GREEN, kFillModeSolid);
		bullet->Draw();
	}
}