#pragma once
#include "Graphics.h"
#include "Dude.h"
#include "FrameTimer.h"

class Poo
{
public:
	void Initialize(float lx, float ly, float lvx, float lvy, bool visibility);
	void Update(float deltaTime);
	bool CollisionTest(Dude& dude);
	void Draw(Graphics& gfx) const;

	//Gets
	static float GetVectorLimit();
	bool GetIsVisible();

	//Sets
	void SetIsVisible();

private:
	float x;
	float y;
	float vx;
	float vy;
	static constexpr int width = 24;
	static constexpr int height = 24;
	static constexpr float vectorLimit = 60.0f; //Pixels per second
	bool isVisible;
};