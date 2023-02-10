#include "EnemyB.h"
#include <Novice.h>


EnemyB::EnemyB() {
	posX_ = 520;
	posY_ = 200;
	speedX_ = 5;
	speedY_ = 5;
	radius_ = 30;

}

void EnemyB::Update() {

	posX_ += speedX_;

	if (posX_ - radius_ <= 0) {
		speedX_ *= -1;
	}
	if (posX_ + radius_ >= 1280) {
		speedX_ *= -1;
	}

}

void EnemyB::Draw() {
	Novice::DrawEllipse(
		posX_, posY_, radius_, radius_,
		0.0f, RED, kFillModeSolid
	);

}