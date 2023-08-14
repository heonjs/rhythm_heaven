#pragma once
#include "Include.h"
#include "Time.h"

namespace JSH
{
	static class ball
	{
	public:
		void Initailize();
		void Update();
		void Render(HDC hdc);

		bool checkx(float x);
		bool checky(float y);
		void move(float x, float y);
		static std::vector<ball> New_Ellipse;

	private:
		float left;
		float top;
		float right;
		float bottom;

		float ballx;
		float bally;

		float speed;

		bool directx;
		bool directy;
	};
}