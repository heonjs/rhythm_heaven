#include "JSHinput.h"
#include "JSHgame.h"
#include "Time.h"

extern JSH::game Game;

namespace JSH
{
	vector<input::Key> input::mKeys = {};
    vector2 input::mMousePos = {};
    vector2 input::PrevMousePos = {};
    float input::mTime = 0.0f;
    float input::PrevTime = 0.0f;

	int ASCII[(int)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M', VK_SPACE,
        VK_LBUTTON, VK_RBUTTON
	};

	void input::Initailize()
	{
		for (int i = 0; i < (int)eKeyCode::End; i++)
		{
			Key key = {};
			key.Code = (eKeyCode)i;
			key.State = eKeyState::None;
			key.bPressed = false;

			mKeys.push_back(key);
		}
	}

	void input::Update()
	{
        HWND hwnd = Game.GetHWND();
        HWND Nowhwnd = GetFocus();

        static float mTime = 0.0f;

        if (hwnd == Nowhwnd)
        {
            for (int i = 0; i < (int)eKeyCode::End; i++)
            {
                POINT MousePos = {};

                // ���� ���콺 Pos �� �޾ƿ´�
                GetCursorPos(&MousePos);

                // ���콺 Pos �� ��ũ�� ��ǥ���� Ư�� Ŭ���̾�Ʈ ��ǥ�� �ٲ��ش�
                ScreenToClient(hwnd, &MousePos);
                mMousePos.x = (float)MousePos.x;
                mMousePos.y = (float)MousePos.y;

                //������ ���� ���� ���� ȣ�� �������� ���� ���� (0x8000)
                if (GetAsyncKeyState(ASCII[i]) & 0x8000)
                {
                    //���� ������ �ִ� ���� (pressed)
                    if (mKeys[i].bPressed == true) //true
                    {
                        mKeys[i].State = eKeyState::Pressed;
                    }
                    else
                    {
                        mKeys[i].State = eKeyState::Down;
                    }

                    mKeys[i].bPressed = true;
                }
                //else if (GetAsyncKeyState(ASCII[i]) & 0)
                else //������ ���� ���� ���� ȣ�� �������� �Է��� �ȵ� ���� (0x0000)
                {
                    //������ ������ �ִ� ����
                    if (mKeys[i].bPressed == true)
                    {
                        mKeys[i].State = eKeyState::Up;
                    }
                    else
                    {
                        mKeys[i].State = eKeyState::None;
                    }

                    mKeys[i].bPressed = false;
                }
            }

        }
        else // ���� ��Ŀ������ �ƴϴ�
        {
            for (UINT i = 0; i < (UINT)eKeyCode::End; i++)
            {
                mKeys[i].bPressed = false;

                if (mKeys[i].State == eKeyState::Down or mKeys[i].State == eKeyState::Pressed)
                {
                    mKeys[i].State = eKeyState::Up;
                }
                else if (mKeys[i].State == eKeyState::Up)
                {
                    mKeys[i].State = eKeyState::None;
                }
            }
        }
	}
}