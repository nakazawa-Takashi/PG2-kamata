#include<Novice.h>
#include"Enemy.h"
#define _USE_MATH_DEFINES
#include <math.h>


Enemy::Enemy(int x, int y) {

	posX_ = x;
	posY_ = y;
	speedX_ = 5;
	radius_ = 30;
	aliv = true;

}

Enemy::~Enemy() {

}




//•œŠˆ
void Enemy::respawn(int a) {

	if (a == false) {
		aliv = false;
	}
	else {
		aliv = true;
	}



}

//“®‚«
void Enemy::Move() {

	if (aliv) {
		posX_ += speedX_;

	}

	if (posX_ - radius_ <= 0) {
		speedX_ *= -1;
	}
	if (posX_ + radius_ >= 1280) {
		speedX_ *= -1;
	}
}


void Enemy::Draw() {
	if (aliv) {
		Novice::DrawEllipse(
			posX_, posY_, radius_, radius_,
			0.0f, RED, kFillModeSolid);
	}
}