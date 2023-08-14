#pragma once
#include "Component.h"
#include "Texture.h"

namespace JSH
{
    using namespace math;
    
    class Texture;
    class Animationmng;
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		virtual ~SpriteRenderer();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

        void SetTexture(Texture* texture)
        {
            mTexture = texture;
        }

        void SetScale(vector2 scale)
        {
            mScale = scale;
        }

        void SetBmpRGB(BYTE r, BYTE g, BYTE b)
        {
            mBmpRGB = RGB(r, g, b);
        }

        float GetAlpha()
        {
            return mAlpha;
        }

        void SetAlpha(float alpha)
        {
            mAlpha = alpha;
        }

	private:
        Texture* mTexture;
        COLORREF mBmpRGB;
        vector2 mScale;
        float mAlpha;
	};
}