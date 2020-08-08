#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Dude
{
public:
	void Controls(const Keyboard& kbd, float deltaTime);
	void Draw(Graphics& gfx) const;
	static constexpr int width = 20;
	static constexpr int height = 20;

private:
	float x = float((Graphics::ScreenWidth / 2) - (width / 2));
	float y = float((Graphics::ScreenHeight / 2) - (height / 2));
	float speedLimit = 360.0f;
	float speedChange = 30.0f;
	float speed = 240.0f;
};