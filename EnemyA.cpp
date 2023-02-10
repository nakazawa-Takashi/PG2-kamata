#include "EnemyA.h"
#include <Novice.h>


EnemyA::EnemyA() {
	posX_ = 20;
	posY_ = 20;
	speedX_ = 55;
	speedY_ = 55;
	radius_ = 10;

}

void EnemyA::Update() {

	posX_ += speedX_;
	posY_ += speedY_;
	if (posX_ - radius_ <= 0) {
		speedX_ *= -1;
	}
	if (posX_ + radius_ >= 1280) {
		speedX_ *= -1;
	}
	if (posY_ - radius_ <= 0) {
		speedY_ *= -1;
	}
	if (posY_ + radius_ >= 720) {
		speedY_ *= -1;
	}
}

void EnemyA::Draw() {
	Novice::DrawEllipse(
		posX_, posY_, radius_, radius_,
		0.0f, WHITE, kFillModeSolid
	);

}