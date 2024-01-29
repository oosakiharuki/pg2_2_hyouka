#include "Enemy.h"

Enemy::Enemy() {
	pos = { 100,50 };
	speedX = 10;	
	speedY = 10;
	radius = 40;
}

void Enemy::Update() {

	pos.x += speedX;
	pos.y += speedY;
	if (pos.x > 1260) {
		speedX = -10;
	}
	if (pos.x < 20) {
		speedX = 10;
	}
	if (pos.y < 20) {
		speedY = 10;
	}
	if (pos.y > 700) {
		speedY = -10;
	}

}

void Enemy::Death() {
	LifeFlag = false;
}

void Enemy::Respawn() {
	LifeFlag = true;
}

void Enemy::Draw() {
	if (LifeFlag == true) {
		Novice::DrawEllipse(pos.x, pos.y, radius, radius, 0.0f, RED, kFillModeSolid);
	}
	else {
		Novice::DrawEllipse(pos.x, pos.y, radius, radius, 0.0f, 0xFFFF00FF, kFillModeSolid);
	}
}
