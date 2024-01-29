#pragma once
#include <Novice.h>
#include"Vector2(int).h"
class Enemy
{
public:

	Enemy();
	void Update();
	void Death();
	void Respawn();
	void Draw();

	int GetPosX() { return pos.x; }
	int GetPosY() { return pos.y; }
	int GetRadius() { return radius; }
	bool GetLife() { return LifeFlag; }

private:
	Vector2 pos;
	int speedX;
	int speedY;
	int radius;
	bool LifeFlag = true;
};

