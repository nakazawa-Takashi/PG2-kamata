#pragma once


class Bullet
{
public:
	Bullet();

	void Move();
	void Draw();
	int GetBulletPosX() { return posX_; };
	int GetBulletPosY() { return posY_; };
	int GetBulletRadius() { return radius_; };

public:
	int posX_ = 0;
	int posY_ = 0;
	int speedX_ = 0;
	int speedY_ = 0;
	int radius_ = 0;
	int isAttack = 0;
};
