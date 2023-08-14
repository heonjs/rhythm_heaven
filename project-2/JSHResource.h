#pragma once
#include "Entity.h"

namespace JSH
{
    class JSHResource : public Entity // 순수 가상함수가 포함되었기 때문에 추상클래스
    {
    public:
        JSHResource();
        virtual ~JSHResource();

        virtual HRESULT Load(const wstring& path) = 0; // 순수 가상함수

        wstring& GetPath()
        {
            return mPath;
        }

        void SetPath(const wstring& path)
        {
            mPath = path;
        }

    private:
        wstring mPath;
    };
}