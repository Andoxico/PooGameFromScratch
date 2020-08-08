#include "Rect.h"

void Rect::Initialize(float lx, float ly)
{
	x = lx;
	y = ly;
	isEaten = false;
}

bool Rect::CollisionTest(Dude& dude)
{
	float boxLeft = x;
	float boxRight = x + width;
	float boxTop = y;
	float boxBottom = y + height;

	float dudeLeft = dude.GetX();
	float dudeRight = dude.GetX() + dude.width;
	float dudeTop = dude.GetY();
	float dudeBottom = dude.GetY() + dude.height;

	if (dudeRight >= boxLeft && 
		dudeLeft <= boxRight && 
		dudeBottom >= boxTop && 
		dudeTop <= boxTop) {
		isEaten = true;
		barRight += barChange;
		if (barRight >= Graphics::ScreenWidth - barBuffer) {
			barRight = Graphics::ScreenWidth - barBuffer;
		}
		return true;
	}
	else {
		return false;
	}
}

bool Rect::GetIsEaten()
{
	return isEaten;
}

void Rect::DrawBox(Graphics& gfx, int timer)
{
	for (int i = int(y); i < int(y + height); i++) {
		for (int j = int(x); j < int(x + width); j++) {
			gfx.PutPixel(j, i, r, gb, gb);
		}
	}
}

void Rect::DrawBar(Graphics& gfx, Color c)
{
	for (int i = barBuffer; i < barBuffer + barHeight; i++) {
		for (int j = barBuffer; j < barRight; j++) {
			gfx.PutPixel(j, i, c);
		}
	}
}
