#pragma once
#include"Vector2(int).h"
#include"Bullet.h"

class Player
{
public:

	int GetPosX() { return pos.x; }
	int GetPosY() { return pos.y; }
	int GetSpeed() { return speed; }
	int GetRadius() { return radius; }
	
	Bullet* bullet = new Bullet;

	Player();
	~Player();
	void Update(char *keys,char *preKeys);
	void Death();
	void Respawn();
	void Draw();

private:
	Vector2 pos;
	int speed;
	int radius;
	bool LifeFlag = true;
};

