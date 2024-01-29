#include "Bullet.h"

Bullet::Bullet() {
	pos = { -100,-100 };
	speed = 20;
	radius = 10;
}

void Bullet::Update() {
	if (isShotFlag == true) {
		pos.y -= speed;
	}
	if (pos.y < -10){
		pos.y = -100;
		isShotFlag = false;
	}
}

void Bullet::BulletFlag(int x, int y) {
	isShotFlag = true;
	pos.x = x;
	pos.y = y;
}


void Bullet::Draw() {
	Novice::DrawEllipse(pos.x, pos.y, radius, radius, 0.0f, BLACK, kFillModeSolid);
}