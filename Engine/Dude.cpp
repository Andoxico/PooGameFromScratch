#include "Dude.h"

void Dude::Controls(const Keyboard& kbd, float deltaTime)
{
	//Local dimensions for easier to understand logical checks
	const int right = int(x + width);
	const int bottom = int(y + height);

	//Local speed to reduce redundant calculations ((speed * deltaTime) must be used whenever speed value is used)
	const float localSpeed = speed * deltaTime;

	if (kbd.KeyIsPressed('A')) {
		x -= localSpeed;
		if (x < 0.0f) {
			x = 0.0f;
		}
	}
	if (kbd.KeyIsPressed('D')) {
		x += localSpeed;
		if (x + width >= float(Graphics::ScreenWidth)) {
			x = float(Graphics::ScreenWidth) - width;
		}
	}

	if (kbd.KeyIsPressed('W')) {
		y -= localSpeed;
		if (y < 0.0f) {
			y = 0.0f;
		}
	}
	if (kbd.KeyIsPressed('S')) {
		y += localSpeed;
		if (y + height >= Graphics::ScreenHeight) {
			y = float(Graphics::ScreenHeight) - height;
		}
	}
}

void Dude::Draw(Graphics& gfx) const
{
#include "face(20x20).txt"
}

void Dude::SpeedUp(bool increase)
{
	if (increase) {
		speed += speedChange;

		if (speed > speedLimit) {
			speed = speedLimit;
		}
	}
}

float Dude::GetX()
{
	return x;
}

float Dude::GetY()
{
	return y;
}
