#include "Dude.h"

void Dude::Controls(const Keyboard& kbd, float deltaTime)
{
	const int right = int(x + width);
	const int bottom = int(y + height);
	const float localSpeed = speed * deltaTime;

	if (kbd.KeyIsPressed('A') && x >= localSpeed) {
		x -= localSpeed;
	}
	else if (kbd.KeyIsPressed('A') && x < localSpeed) {
		x = 0.0f;
	}

	if (kbd.KeyIsPressed('D') && right <= Graphics::ScreenWidth - localSpeed) {
		x += localSpeed;
	}
	else if (kbd.KeyIsPressed('D') && right > Graphics::ScreenWidth - localSpeed) {
		x = float(Graphics::ScreenWidth - width);
	}

	if (kbd.KeyIsPressed('W') && y >= localSpeed) {
		y -= localSpeed;
	}
	else if (kbd.KeyIsPressed('W') && y < localSpeed) {
		y = 0.0f;
	}

	if (kbd.KeyIsPressed('S') && bottom <= Graphics::ScreenHeight - localSpeed) {
		y += localSpeed;
	}
	else if (kbd.KeyIsPressed('S') && bottom > Graphics::ScreenHeight - localSpeed) {
		y = float(Graphics::ScreenHeight - height);
	}
}

void Dude::Draw(Graphics& gfx) const
{
#include "face(20x20).txt"
}
