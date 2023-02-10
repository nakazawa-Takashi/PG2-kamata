#pragma once
#include"Enemy.h"

class EnemyA : public Enemy
{
public:
	EnemyA();
	~EnemyA();
	void Update() override;
	void Draw() override;


};