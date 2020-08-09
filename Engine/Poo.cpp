#include "Poo.h"

void Poo::Initialize(float lx, float ly, float lvx, float lvy, bool visibility)
{
	x = lx;
	y = ly;
	vx = lvx;
	vy = lvy;
	isVisible = visibility;
}

void Poo::Update(float deltaTime)
{
	float right = x + float(width);
	float bottom = y + float(height);
	float local_vx = vx * deltaTime;
	float local_vy = vy * deltaTime;

	float screenWidth = float(Graphics::ScreenWidth - 1);
	float screenHeight = float(Graphics::ScreenHeight - 1);


	//Don't ask how these work just accept it
	float tempRight = right - screenWidth;
	tempRight = -(local_vx + tempRight);
	float tempX = tempRight + screenWidth;
	tempX -= float(width);

	float tempBottom = bottom - screenHeight;
	tempBottom = -(local_vy + tempBottom);
	float tempY = tempBottom + screenHeight;
	tempY -= float(height);
	//

	if (x + local_vx <= 0.0f) {
		x = -(local_vx - x);
		vx = -vx;
	}
	else if (right + local_vx >= screenWidth) {
		x = tempX;
		vx = -vx;
	}

	if (y + local_vy <= 0.0f) {
		y = -(local_vy - y);
		vy = -vy;
	}
	else if (bottom + local_vy >= screenHeight) {
		y = tempY;
		vy = -vy;
	}

	x += local_vx;
	y += local_vy;
}

bool Poo::CollisionTest(Dude& dude)
{
	float dudeLeft = dude.GetX();
	float dudeRight = dude.GetX() + dude.width;
	float dudeTop = dude.GetY();
	float dudeBottom = dude.GetY() + dude.height;

	float pooLeft = x;
	float pooRight = x + width;
	float pooTop = y;
	float pooBottom = y + height;

	if (isVisible) {
		return (dudeRight >= pooLeft &&
				dudeLeft <= pooRight &&
				dudeBottom >= pooTop &&
				dudeTop <= pooBottom);
	}
	else {
		return false;
	}
}

void Poo::Draw(Graphics& gfx) const
{
#include "poo(24x24).txt"
}

float Poo::GetVectorLimit()
{
	return vectorLimit;
}

bool Poo::GetIsVisible()
{
	return isVisible;
}

void Poo::SetIsVisible()
{
	isVisible = true;
}
