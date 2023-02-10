#pragma once

class Object
{
public:

	virtual void Move();
	virtual void distance(int x, int y, int r);
	virtual void Draw();

protected:
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_;
};