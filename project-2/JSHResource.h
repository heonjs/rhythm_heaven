#pragma once
#include "Entity.h"

namespace JSH
{
    class JSHResource : public Entity // ���� �����Լ��� ���ԵǾ��� ������ �߻�Ŭ����
    {
    public:
        JSHResource();
        virtual ~JSHResource();

        virtual HRESULT Load(const wstring& path) = 0; // ���� �����Լ�

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