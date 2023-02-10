#pragma once
#include"Object.h"
#include "Bullet.h"

class Player : protected Object
{
public:
	Player();
	~Player();

	//プレーヤーの値
	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetRadius() { return radius_; };

	int EnemyGetAliv() { return enemyAliv; };


	void Move(char* keys, char* preKeys);
	void BulletDistance(char* keys, char* preKeys, int x, int y, int r, int a);
	void Draw() override;

private:
	Bullet bullet_[50];
	int time;
	//当たり判定
	//弾と敵
	int c[50];
	int d[50];
	int hantei[50];
	int enemyAliv;
};