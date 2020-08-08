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
	int x;
	int y;
	static constexpr int width = 24;
	static constexpr int height = 24;
	bool isEaten = true;
	int r = 255;

	//Bar
	int barBuffer = 10;
	int barRight = barBuffer;
	int barHeight = 25;
	int barChange = 50;
};