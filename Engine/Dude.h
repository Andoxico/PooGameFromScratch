#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Dude
{
public:
	void Controls(const Keyboard& kbd, float deltaTime);
	void Draw(Graphics& gfx) const;
	void SpeedUp();
	float GetX();
	float GetY();
	static constexpr float width = 20;
	static constexpr float height = 20;

private:
	float x = float((Graphics::ScreenWidth / 2) - (width / 2));
	float y = float((Graphics::ScreenHeight / 2) - (height / 2));
	float speedLimit = 360.0f;
	float speedChange = 30.0f;
	float speed = 120.0f;
};