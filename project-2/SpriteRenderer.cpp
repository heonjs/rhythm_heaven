#include "SpriteRenderer.h"
#include "Transform.h"
#include "GameObject.h"

namespace JSH
{
    SpriteRenderer::SpriteRenderer()
        : Component(eComponentType::SpriteRender)
        , mTexture(nullptr)
        , mBmpRGB(RGB(0, 60, 104))
        , mScale(vector2::One)
        , mAlpha(1.0f)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{
        if (mTexture == nullptr)
        {
            return;
        }

        GameObject* gameobj = GetOwner();
        Transform* tr = gameobj->GetComponent<Transform>();
        mTexture->Render(hdc
            , tr->GetPosition()
            , vector2(mTexture->GetWidth(), mTexture->GetHeight())
            , vector2(0.0f, 0.0f)
            , vector2(mTexture->GetWidth(), mTexture->GetHeight())
            , vector2::Zero
            , mScale, mAlpha, mBmpRGB);
	}
}