#pragma once
#include "Dude.h"
#include "Graphics.h"

class Rect
{
public:
	void Initialize(float lx, float ly);
	bool CollisionTest(Dude& dude);
	bool GetIsEaten();
	void DrawBox(Graphics& gfx, int timer);
	void DrawBar(Graphics& gfx, Color c);

private:
	//Box
	float x;
	float y;
	static constexpr float width = 24;
	static constexpr float height = 24;
	bool isEaten = true;
	int r = 255;
	int gb;

	//Bar
	int barBuffer = 10;
	int barRight = barBuffer;
	int barHeight = 25;
	int barChange = 50;
};