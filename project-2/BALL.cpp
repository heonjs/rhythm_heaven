#include "BALL.h"
#include"Include.h"
#include"Time.h"

namespace JSH
{
	vector<ball> ball::New_Ellipse = {};

	void JSH::ball::Initailize()
	{
		ball mNew = {};

		mNew.ballx = 100.0f;
		mNew.bally = 100.0f;
		mNew.directx = true;
		mNew.directy = true;
		mNew.speed = 400.0f;
		mNew.checkx(mNew.ballx);
		mNew.checky(mNew.bally);

		New_Ellipse.push_back(mNew);
	}

	void JSH::ball::Update()
	{
		move(ballx, bally);

		left = ballx - 50;
		top = bally - 50;
		right = ballx + 50;
		bottom = bally + 50;
	}

	void JSH::ball::Render(HDC hdc)
	{
		for (int i = 0; i < New_Ellipse.size(); i++)
		{
			Ellipse(hdc, New_Ellipse[i].left, New_Ellipse[i].top, New_Ellipse[i].right, New_Ellipse[i].bottom);
		}
	}

	bool ball::checkx(float ballx)
	{
		for (int i = 0; i < New_Ellipse.size(); i++)
		{
			if (New_Ellipse[i].ballx >= 1024 - 50)
			{
				New_Ellipse[i].directx = false;
				return New_Ellipse[i].directx;
			}
			else if (New_Ellipse[i].ballx <= 0 + 50)
			{
				New_Ellipse[i].directx = true;
				return New_Ellipse[i].directx;
			}

			return New_Ellipse[i].directx;
		}
	}

	bool ball::checky(float bally)
	{
		for (int i = 0; i < New_Ellipse.size(); i++)
		{
			if (New_Ellipse[i].bally >= 720 - 50)
			{
				New_Ellipse[i].directy = false;
				return New_Ellipse[i].directy;
			}
			else if (New_Ellipse[i].bally <= 0 + 50)
			{
				New_Ellipse[i].directy = true;
				return New_Ellipse[i].directy;
			}

			return New_Ellipse[i].directy;
		}
	}

	void JSH::ball::move(float x, float y)
	{
		if (checkx(ballx) == true)
		{
			ballx += speed * Time::DeltaTime();
		}
		else if (checkx(ballx) == false)
		{
			ballx -= speed * Time::DeltaTime();
		}

		if (checky(bally) == true)
		{
			bally += speed * Time::DeltaTime();
		}
		else if (checky(bally) == false)
		{
			bally -= speed * Time::DeltaTime();
		}
	}
}