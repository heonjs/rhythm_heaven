#include "Animationmng.h"
#include "JSHResourcemng.h"
#include "Texture.h"

namespace JSH
{
    Animationmng::Animationmng()
        :Component(eComponentType::Animationmng)
        , mAlpha(1.0f)
        , mScale(vector2::One)
    {
    }
    Animationmng::~Animationmng()
    {
        for (auto iter : mAnimations)
        {
            delete iter.second;
            iter.second = nullptr;
        }
    }
    void Animationmng::Initialize()
    {
    }
    void Animationmng::Update()
    {
        if (mActiveAnimation)
        {
            mActiveAnimation->Update();
            if (mActiveAnimation->IsComplete() and mbLoop)
            {
                mActiveAnimation->Reset();
            }
        }
    }
    void Animationmng::Render(HDC hdc)
    {
        if (mActiveAnimation)
        {
            mActiveAnimation->Render(hdc);
        }
    }
    Animation* Animationmng::CreateAnimation(const wstring& name, Texture* texture
        , vector2 lefttop, vector2 size, UINT spriteLength
        , vector2 offset, float duration)
    {
        Animation* animation = nullptr;
        animation = FindAnimation(name);
        if (animation != nullptr)
        {
            return animation;
        }
        
        animation = new Animation();
        animation->Create(name, texture
            , lefttop, size, offset
            , spriteLength, duration);
        animation->SetAnimationmng(this);

        mAnimations.insert(make_pair(name, animation));

        return animation;
    }

    void Animationmng::CreateAnimationFolder(const wstring& name, const wstring& path
        , vector2 offset, float duration)
    {
        UINT width = 0;
        UINT height = 0;
        UINT filecount = 0;

        filesystem::path fs(path);
        vector<Texture*> images = {};
        eTextureType temptype = eTextureType::None;

        for (auto& p : filesystem::recursive_directory_iterator(path))
        {
            wstring FileName = p.path().filename();
            wstring FilePath = p.path();

            Texture* image = JSHResourcemng::Load<Texture>(FileName, FilePath);
            temptype = image->GetType();
            images.push_back(image);

            if (width < image->GetWidth())
            {
                width = image->GetWidth();
            }
            if (height < image->GetHeight())
            {
                height = image->GetHeight();
            }

            filecount++;
        }
        wstring spriteSheetName = name + L"SpriteSheet";
        Texture* spriteSheet = Texture::Create(spriteSheetName, width * filecount, height);
        spriteSheet->SetType(temptype);

        int idx = 0;
        for (Texture* image : images)
        {
            BitBlt(spriteSheet->GetHDC()
                ,(width * idx) + ((width - image->GetWidth()) / 2.0f)
                , 0, image->GetWidth(), image->GetHeight()
                , image->GetHDC(), 0, 0, SRCCOPY);

            idx++;
        }

        CreateAnimation(name, spriteSheet, vector2(0.0f, 0.0f)
            , vector2(width, height), filecount, offset, duration);
    }

    Animation* Animationmng::FindAnimation(const wstring& name)
    {
        auto iter = mAnimations.find(name);
        
        if (iter == mAnimations.end())
        {
            return nullptr;
        }
        return iter->second;
    }

    void Animationmng::PlayAnimation(const wstring& name, bool loop)
    {
        Animation* animation = FindAnimation(name);
        if (animation == nullptr)
        {
            return;
        }

        mActiveAnimation = animation;
        mActiveAnimation->Reset();
        mbLoop = loop;
    }
}