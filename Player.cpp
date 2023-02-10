#include <Novice.h>
#include"Player.h"
#define _USE_MATH_DEFINES
#include <math.h>


Player::Player()
{
	for (int i = 0; i < 50; i++) {
		bullet_[i];
		c[i] = 0;
		d[i] = 0;
		hantei[i] = 0;

	}

	posX_ = 600;
	posY_ = 600;
	speedX_ = 7;
	speedY_ = 7;
	radius_ = 30;


	time = 0;
	enemyAliv = true;

}




// ’e‚Ì“–‚½‚è”»’è
void Player::BulletDistance(char* keys, char* preKeys, int x, int y, int r, int a) {

	if (!a) {
		if (keys[DIK_R]) {
			enemyAliv = true;
		}

	}
	else {
		for (int i = 0; i < 50; i++) {
			c[i] = x - bullet_[i].posX_;
			d[i] = y - bullet_[i].posY_;
			hantei[i] = sqrt(c[i] * c[i] + d[i] * d[i]);
			if (bullet_[i].radius_ + r >= hantei[i] && bullet_[i].isAttack) {
				enemyAliv = false;
				bullet_[i].isAttack = false;
			}
		}
	}
}

//’e‚Ì”­ŽË‚ÆˆÚ“®
void Player::Move(char* keys, char* preKeys) {

	time++;
	if (time == 8) {
		time = 0;
	}
	if (keys[DIK_W]) {
		posY_ -= speedY_;
	}
	if (keys[DIK_S]) {
		posY_ += speedY_;
	}
	if (keys[DIK_A]) {
		posX_ -= speedX_;
	}
	if (keys[DIK_D]) {
		posX_ += speedX_;
	}

	for (int i = 0; i < 50; i++) {
		if (keys[DIK_SPACE] && bullet_[i].isAttack == false && time == 0) {
			bullet_[i].isAttack = true;
			bullet_[i].posX_ = posX_;
			bullet_[i].posY_ = posY_;
			break;
		}

	}

	for (int i = 0; i < 50; i++) {

		if (bullet_[i].isAttack) {
			bullet_[i].Move();
			if (bullet_[i].posY_ - bullet_[i].radius_ <= 0) {
				bullet_[i].isAttack = false;
			}
		}


	}






}

void Player::Draw() {

	Novice::DrawEllipse(
		posX_, posY_,
		radius_, radius_,
		0.0f, 0x00FF00FF, kFillModeSolid

	);
	for (int i = 0; i < 50; i++) {
		if (bullet_[i].isAttack) {
			bullet_[i].Draw();
		}
	}

}
