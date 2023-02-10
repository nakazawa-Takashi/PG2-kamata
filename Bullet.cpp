#include <Novice.h>
#include "Bullet.h"

Bullet::Bullet() {
	posX_ = 20;
	posY_ = 20;
	speedX_ = 7;
	speedY_ = 7;
	radius_ = 10;
	isAttack = false;
}

void Bullet::Move() {
	posY_ -= speedY_;
}

void Bullet::Draw() {
	Novice::DrawEllipse(
		posX_, posY_, radius_, radius_,
		0.0f, WHITE, kFillModeSolid);
}
