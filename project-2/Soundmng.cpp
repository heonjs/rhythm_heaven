#include "Soundmng.h"
#include "JSHgame.h"

extern JSH::game Game;

namespace JSH
{
    LPDIRECTSOUND8 Soundmng::mSoundDevice;

    bool Soundmng::Initialize()
    {
        if (FAILED(DirectSoundCreate8(NULL, &mSoundDevice, NULL)))
        {
            MessageBox(NULL, L"�������̽���������", L"SYSTEM ERROR", MB_OK);
            return false;
        }

        // ���� ����̽� �������� ����.
        HWND hwnd = Game.GetHWND();
        if (FAILED(mSoundDevice->SetCooperativeLevel(hwnd, DISCL_EXCLUSIVE))) // Flag�� ����
        {
            MessageBox(NULL, L"�������̽� �������� ����", L"SYSTEM ERROR", MB_OK);
            return false;
        }

        return true;
    }
}