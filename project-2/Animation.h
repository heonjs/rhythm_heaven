#pragma once
#include "JSHResource.h"

namespace JSH
{
    using namespace math;

    class Texture;
    class Animationmng;
    class Animation : public JSHResource
    {
    public:
        struct Sprite
        {
            vector2 lefttop; // 사진의 시작지점 좌표
            vector2 size;    // 사진의 픽셀 크기
            vector2 offset;  // 애니메이션 중심 좌표
            float duration;  // 사진1에서 사진2로 넘어가는데 걸리는 시간

            Sprite()
                : lefttop(vector2::Zero)
                , size(vector2::Zero)
                , offset(vector2::Zero)
                , duration(0.0f)
            {
            }
        };

        Animation();
        virtual ~Animation();

        virtual void Update();
        virtual void Render(HDC hdc);

        virtual HRESULT Load(const wstring& path)
        {
            return S_FALSE;
        }

        void Create(const wstring& name
            , class Texture* texture
            , vector2 lefttop, vector2 size, vector2 offset
            , UINT spritelength, float duration);

        void Reset();

        bool IsComplete()
        {
            return mbComplete;
        }
        void SetAnimationmng(Animationmng* animationmng)
        {
            mAnimationmng = animationmng;
        }

        void SetBmpRGB(BYTE r, BYTE g, BYTE b)
        {
            mBmpRGB = RGB(r, g, b);
        };

        void SetScale(vector2 scale)
        {
            mScale = scale;
        }

    private:
        Animationmng* mAnimationmng;
        Texture* mTexture;

        vector<Sprite> mSpriteSheet;
        int mIndex;
        float mTime;
        bool mbComplete; // 애니메이션이 끝나면 true로 바뀐다.
        COLORREF mBmpRGB;
        vector2 mScale;
    };
}