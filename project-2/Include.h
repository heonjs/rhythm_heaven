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
        End //End는 string의 '\0' 처럼 꼭 붙여준다.
    };

    enum class eComponentType
    {
        Transform, //위치 좌표
        SpriteRender, //렌더 이미지
        Animation,
        Animationmng,
        Collider,
        End
    };
};

//include는 class의 객체를 만들어야 멤버변수나 함수를 사용할 수 있는데
//상속은 만들 필요 없이 멤버변수와 함수를 사용 가능하다.