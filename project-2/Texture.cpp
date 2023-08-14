#include "Texture.h"
#include "JSHgame.h"
#include "JSHResourcemng.h"
#include "GameObject.h"

extern JSH::game Game;

namespace JSH
{
    Texture::Texture()
        : mImage(nullptr)
        , mBitmap(NULL)
        , mHDC(NULL)
        , mWidth(0)
        , mHeight(0)
        , mType(eTextureType::None)
    {
    }
    Texture::~Texture()
    {
        delete mImage;
        mImage = nullptr;

        DeleteObject(mBitmap);
        mBitmap = NULL;
    }
    Texture* Texture::Create(const wstring& name, UINT width, UINT height)
    {
        Texture* image = JSHResourcemng::Find<Texture>(name);
        if (image != nullptr)
        {
            return image;
        }

        image = new Texture();
        image->SetWidth(width);
        image->SetHeight(height);

        HDC hdc = Game.GetHDC();
        HBITMAP bitmap = CreateCompatibleBitmap(hdc, width, height);
        image->SetHBitmap(bitmap);

        HDC bitmapHDC = CreateCompatibleDC(hdc);
        image->SetHDC(bitmapHDC);

        HBITMAP defaultBitmap = (HBITMAP)SelectObject(bitmapHDC, bitmap);
        DeleteObject(defaultBitmap);

        image->SetName(name);
        image->SetType(eTextureType::AlphaBmp);
        JSHResourcemng::Insert<Texture>(name, image);

        return image;
    }
    HRESULT Texture::Load(const wstring& path) // HRESULT : 32��Ʈ signed�� ����, booló�� ��� ����
    {
        // .bmp �� ���� .png �� ���� �����ش�.

        wstring ext = path.substr(path.find_last_of(L".") + 1); // "." ���� ���� Ȯ���ڸ��� ã�´�.

        if (ext == L"bmp")
        {
            mType = eTextureType::Bmp;
            mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

            if (mBitmap == nullptr)
            {
                return E_FAIL; //S_FALSE;
            }
            //S_FALSE : ���������� �߰� �۾��� �ʿ��� ��� ���
            //E_FAIL : ����

            BITMAP info = {};
            GetObject(mBitmap, sizeof(BITMAP), &info);

            mWidth = info.bmWidth;
            mHeight = info.bmHeight;

            HDC mainDC = Game.GetHDC();
            mHDC = CreateCompatibleDC(mainDC);

            HBITMAP defaultBitmap = (HBITMAP)SelectObject(mHDC, mBitmap);
            DeleteObject(defaultBitmap);
        }
        else if (ext == L"png")
        {
            mType = eTextureType::Png; // image.png ������ �̿��Ͽ� Texture ��ü�� ����
            mImage = Gdiplus::Image::FromFile(path.c_str());

            mWidth = mImage->GetWidth();
            mHeight = mImage->GetHeight();
        }

        return S_OK;
    }

    void Texture::Render(HDC hdc
        , vector2 pos, vector2 size
        , vector2 lefttop, vector2 rightbottom
        , vector2 offset, vector2 scale, float alpha
        , COLORREF rgb)
    {
        if (mBitmap == nullptr and mImage == nullptr)
        {
            return;
        }

        if (mType == eTextureType::Bmp)
        {
            TransparentBlt(hdc, (int)pos.x - (size.x * scale.x / 2.0f) + offset.x
                , (int)pos.y - (size.y * scale.y / 2.0f) + offset.y
                , size.x * scale.x
                , size.y * scale.y
                , mHDC, lefttop.x, lefttop.y, rightbottom.x, rightbottom.y
                , rgb);
        }
        else if (mType == eTextureType::AlphaBmp)
        {
            BLENDFUNCTION func = {};
            func.BlendOp = AC_SRC_OVER;
            func.BlendFlags = 0;
            func.AlphaFormat = AC_SRC_ALPHA;
            // 0.0f ~ 1.0f -> 0 ~ 255
            
            alpha = (int)(alpha * 255.0f);

            if (alpha <= 0)
            {
                alpha = 0;
            }
            func.SourceConstantAlpha = alpha; // 0 ~ 255

            AlphaBlend(hdc, (int)pos.x - (size.x * scale.x / 2.0f) + offset.x
                , (int)pos.y - (size.y * scale.y / 2.0f) + offset.y
                , size.x * scale.x
                , size.y * scale.y
                , mHDC
                , lefttop.x, lefttop.y
                , rightbottom.x, rightbottom.y
                , func);
        }
        else if (mType == eTextureType::Png)
        {
            // ���� ���ϴ� �ȼ��� ����ȭ ��ų��
            Gdiplus::ImageAttributes imageAtt = {};
            // ����ȭ ��ų �ȼ� �� ����
            imageAtt.SetColorKey(Gdiplus::Color(100, 100, 100)
                , Gdiplus::Color(255, 255, 255));

            Gdiplus::Graphics graphics(hdc);
            graphics.DrawImage(mImage
                , Gdiplus::Rect
                (
                    (int)(pos.x - (size.x * scale.x / 2.0f) + offset.x)
                    , (int)(pos.y - (size.y * scale.y / 2.0f) + offset.y)
                    , (int)(size.x * scale.x)
                    , (int)(size.y * scale.y)
                )
                , lefttop.x, lefttop.y
                , rightbottom.x, rightbottom.y
                , Gdiplus::UnitPixel
                , nullptr);
        }
    }
}