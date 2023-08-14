#include "Time.h"

namespace JSH
{
	LARGE_INTEGER Time::mCpuFrequency = {};
	LARGE_INTEGER Time::mPrevFrequency = {};
	LARGE_INTEGER Time::mCurFrequency = {};

	float Time::mDeltaTime = 0.0f;

	void JSH::Time::Initailize()
	{
		//CPU의 고유 진동 수(Hz)를 가져온다
		QueryPerformanceFrequency(&mCpuFrequency);

		//프로그램 시작됐을 때의 진동 수를 가져온다
		QueryPerformanceCounter(&mPrevFrequency);
	}

	void JSH::Time::Update()
	{
		QueryPerformanceCounter(&mCurFrequency);

		float differenceFrequency //진동 수의 차
			= static_cast<float>(mCurFrequency.QuadPart
				-mPrevFrequency.QuadPart);

		//프레임과 프레임 사이의 시간
		mDeltaTime = differenceFrequency / static_cast<float>(mCpuFrequency.QuadPart);
		mPrevFrequency.QuadPart = mCurFrequency.QuadPart;
	}

	void JSH::Time::Render(HDC hdc)
	{
		static float timecheck = 0.0f;

		timecheck += mDeltaTime;

		if (timecheck >= 1.0f)
		{
			wchar_t szFloat[50] = {};
			float fps = 1.0f / mDeltaTime;

			swprintf_s(szFloat, 50, L"fps : %f", fps);

			int strlen = wcsnlen_s(szFloat, 50);

			TextOut(hdc, 10, 10, szFloat, strlen);

			timecheck = 0.0f;
		}
	}
}