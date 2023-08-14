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
            vector2 lefttop; // ������ �������� ��ǥ
            vector2 size;    // ������ �ȼ� ũ��
            vector2 offset;  // �ִϸ��̼� �߽� ��ǥ
            float duration;  // ����1���� ����2�� �Ѿ�µ� �ɸ��� �ð�

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
        bool mbComplete; // �ִϸ��̼��� ������ true�� �ٲ��.
        COLORREF mBmpRGB;
        vector2 mScale;
    };
}