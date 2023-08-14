#include "Time.h"

namespace JSH
{
	LARGE_INTEGER Time::mCpuFrequency = {};
	LARGE_INTEGER Time::mPrevFrequency = {};
	LARGE_INTEGER Time::mCurFrequency = {};

	float Time::mDeltaTime = 0.0f;

	void JSH::Time::Initailize()
	{
		//CPU�� ���� ���� ��(Hz)�� �����´�
		QueryPerformanceFrequency(&mCpuFrequency);

		//���α׷� ���۵��� ���� ���� ���� �����´�
		QueryPerformanceCounter(&mPrevFrequency);
	}

	void JSH::Time::Update()
	{
		QueryPerformanceCounter(&mCurFrequency);

		float differenceFrequency //���� ���� ��
			= static_cast<float>(mCurFrequency.QuadPart
				-mPrevFrequency.QuadPart);

		//�����Ӱ� ������ ������ �ð�
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