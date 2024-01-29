#pragma once
#include"Vector2(int).h"
#include <Novice.h>

class Bullet
{
public:
	Bullet();
	void Update();
	void BulletFlag(int x,int y);
	void Draw();

	int GetPosX() { return pos.x; }
	int GetPosY() { return pos.y; }
	int GetSpeed() { return speed; }
	int GetRadius() { return radius; }
	bool GetShotFlag() { return isShotFlag; }

private:
	Vector2 pos;
	int speed;
	int radius;
	bool isShotFlag;
};

