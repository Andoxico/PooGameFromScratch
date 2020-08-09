#include "Rect.h"

void Rect::Initialize(float lx, float ly)
{
	x = int(lx);
	y = int(ly);
	isEaten = false;
}

bool Rect::CollisionTest(Dude& dude)
{
	int boxLeft = x;
	int boxRight = x + width;
	int boxTop = y;
	int boxBottom = y + height;

	int dudeLeft = int(dude.GetX());
	int dudeRight = int(dude.GetX() + dude.width);
	int dudeTop = int(dude.GetY());
	int dudeBottom = int(dude.GetY() + dude.height);

	if (dudeRight >= boxLeft && 
		dudeLeft <= boxRight && 
		dudeBottom >= boxTop && 
		dudeTop <= boxBottom) {
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
			gfx.PutPixel(j, i, r, timer, timer);
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
