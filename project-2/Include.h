#pragma once
#include <vector>
#include<list>
#include<map>
#include<set>
#include<functional>
#include <string>
#include <filesystem>
#include <bitset>
#include <assert.h>

#include "framework.h"
#include "JSHmath.h"

#pragma comment (lib, "Msimg32.lib")

#include <mmsystem.h>
#include <dsound.h>
#include <dinput.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dsound.lib")

using namespace std;

namespace JSH::enums
{
    enum class eLayerType
    {
        BackGround,
        BackGroundObject,
        Ingame,
        NPC1,
        NPC2,
        Player,
        TouchScreen,
        FrontObject,        
        Effect,
        UI,
        Cursor,
        End //End�� string�� '\0' ó�� �� �ٿ��ش�.
    };

    enum class eComponentType
    {
        Transform, //��ġ ��ǥ
        SpriteRender, //���� �̹���
        Animation,
        Animationmng,
        Collider,
        End
    };
};

//include�� class�� ��ü�� ������ ��������� �Լ��� ����� �� �ִµ�
//����� ���� �ʿ� ���� ��������� �Լ��� ��� �����ϴ�.