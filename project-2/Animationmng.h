#pragma once
#include "Component.h"
#include "Animation.h"

namespace JSH
{
    using namespace math;
    class Animationmng : public Component
    {
    public:
        Animationmng();
        virtual ~Animationmng();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        Animation* CreateAnimation(const wstring& name, class Texture* texture
            , vector2 lefttop, vector2 size, UINT spriteLength
            , vector2 offset = vector2::Zero, float duration = 0.1f);

        void CreateAnimationFolder(const wstring& name, const wstring& path
            , vector2 offset = vector2::Zero, float duration = 0.1f);

        Animation* FindAnimation(const wstring& name);

        void PlayAnimation(const wstring& name, bool loop = false);

        bool IsActiveAnimationComplete()
        {
            return mActiveAnimation->IsComplete();
        }

        float GetAlpha()
        {
            return mAlpha;
        }
        void SetAlpha(float alpha)
        {
            mAlpha = alpha;
        }

        vector2 GetScale()
        {
            return mScale;
        }
        void SetScale(vector2 scale)
        {
            mScale = scale;
        }

        void SetBmpRGB(const wstring& name, BYTE r, BYTE g, BYTE b)
        { 
            Animation* Fa =  FindAnimation(name);
            if (Fa != nullptr)
            {
                Fa->SetBmpRGB(r, g, b);
            }
        };

    private:
        map<wstring, Animation*> mAnimations;

        Animation* mActiveAnimation; //현재 움직이는 애니메이션
        bool mbLoop;
        float mAlpha;
        vector2 mScale;
   
    };
}