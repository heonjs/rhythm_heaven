#include "Animation.h"
#include "Texture.h"
#include "Animationmng.h"
#include "Time.h"
#include "Transform.h"
#include "GameObject.h"

namespace JSH
{
    Animation::Animation()
        : mAnimationmng(nullptr)
        , mTexture(nullptr)
        , mSpriteSheet{}
        , mIndex(-1)
        , mTime(0.0f)
        , mbComplete(false)
        , mScale(vector2::One)
        , mBmpRGB(RGB(0, 60, 104))
    {
    }
    Animation::~Animation()
    {
    }
    void Animation::Update()
    {
        if (mbComplete)
        {
            return;
        }

        mTime += Time::DeltaTime();
        if (mSpriteSheet[mIndex].duration < mTime)
        {
            mTime = 0.0f;

            if (mIndex < mSpriteSheet.size() - 1)
            {
                mIndex++;
            }
            else
            {
                mbComplete = true;
            }
        }
    }
    void Animation::Render(HDC hdc)
    {
        if (mTexture == nullptr)
        {
            return;
        }

        Sprite sprite = mSpriteSheet[mIndex];

        Transform* tr = mAnimationmng->GetOwner()->GetComponent<Transform>();
        vector2 pos = tr->GetPosition();

        Animationmng* animationmng = mAnimationmng;

        mTexture->Render(hdc, pos
            , sprite.size, sprite.lefttop, sprite.size, sprite.offset
            , animationmng->GetScale(), animationmng->GetAlpha(), mBmpRGB);
    }
    void Animation::Create(const wstring& name, Texture* texture
        , vector2 lefttop, vector2 size, vector2 offset
        , UINT spritelength, float duration)
    {
        mTexture = texture;

        for (size_t i = 0; i < spritelength; i++)
        {
            Sprite sprite = {};

            sprite.lefttop.x = lefttop.x + (size.x * i);
            sprite.lefttop.y = lefttop.y;
            if (sprite.lefttop.x >= texture->GetWidth())
            {
                sprite.lefttop.x = sprite.lefttop.x - texture->GetWidth();
                sprite.lefttop.y = lefttop.y + size.y;
            }
            sprite.size = size;
            sprite.offset = offset;
            sprite.duration = duration;

            mSpriteSheet.push_back(sprite);
        }
    }
    void Animation::Reset()
    {
        mTime = 0.0f;
        mIndex = 0;
        mbComplete = false;
    }
}