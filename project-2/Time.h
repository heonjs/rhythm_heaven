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
		//cpu�� ���� ���� ��(Hz)
		static LARGE_INTEGER mCpuFrequency; 

		//���α׷��� ���۵��� ���� ���� ��
		static LARGE_INTEGER mPrevFrequency;

		//���� �������� ���� ��
		static LARGE_INTEGER mCurFrequency;

		static float mDeltaTime;
	};

}