#pragma once
#include "Include.h"

namespace JSH
{
	class Time
	{
	public:
		static void Initailize();
		static void Update();
		static void Render(HDC hdc);

		__forceinline static float DeltaTime()
		{
			return mDeltaTime;
		}

	private:
		//cpu의 고유 진동 수(Hz)
		static LARGE_INTEGER mCpuFrequency; 

		//프로그램이 시작됐을 때의 진동 수
		static LARGE_INTEGER mPrevFrequency;

		//현재 프레임의 진동 수
		static LARGE_INTEGER mCurFrequency;

		static float mDeltaTime;
	};

}