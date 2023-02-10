#pragma once
#include "Object.h"
#include "Bullet.h"

class Enemy : protected Object
{
public:
	static int enemyCount;
	Enemy(int x, int y);
	~Enemy();

	//“G‚Ì’l
	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetRadius() { return radius_; };
	int GetAliv() { return aliv; };


	void respawn(int a);
	void Move()override;
	void Draw()override;

private:
	int aliv;



};
