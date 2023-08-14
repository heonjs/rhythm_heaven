#pragma once
#include "JSHResource.h"

namespace JSH
{
    using namespace math;

    enum class eTextureType
    {
        Bmp,
        AlphaBmp,
        Png,
        None
    };

    class Texture : public JSHResource
    {
    public:
        Texture();
        virtual ~Texture();

        static Texture* Create(const wstring& name, UINT width, UINT height);

        virtual HRESULT Load(const wstring& path) override;

        void Render(HDC hdc
            , vector2 pos
            , vector2 size
            , vector2 lefttop
            , vector2 rightbottom
            , vector2 offset = vector2::Zero
            , vector2 scale = vector2::One
            , float alpha = 1.0f
            , COLORREF rgb = RGB(0, 60, 104));

        UINT GetWidth()
        {
            return mWidth;
        }
        void SetWidth(UINT width)
        {
            mWidth = width;
        }

        UINT GetHeight()
        {
            return mHeight;
        }
        void SetHeight(UINT height)
        {
            mHeight = height;
        }

        HDC GetHDC()
        {
            return mHDC;
        }
        eTextureType GetType()
        {
            return mType;
        }
        void SetType(eTextureType type)
        {
            mType = type;
        }

        Gdiplus::Image* GetImage()
        {
            return mImage;
        }

        void SetHBitmap(HBITMAP bitmap)
        {
            mBitmap = bitmap;
        }
        void SetHDC(HDC hdc)
        {
            mHDC = hdc;
        }

    private:
        eTextureType mType;
        Gdiplus::Image* mImage;
        
        HBITMAP mBitmap;
        HDC mHDC;
        UINT mWidth;
        UINT mHeight;
    };
}