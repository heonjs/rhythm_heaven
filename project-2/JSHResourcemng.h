#pragma once
#include "JSHResource.h"

namespace JSH
{
    class JSHResourcemng
    {
    public:
        template<typename T>
        static T* Find(const wstring& name)
        {
            auto iter = mResources.find(name);
            if (iter == mResources.end())
            {
                return nullptr;
            }
            return dynamic_cast<T*>(iter->second);
        }

        template<typename T>
        static T* Load(const wstring& name, const wstring& path)
        {
            T* resource = JSHResourcemng::Find<T>(name);

            if (resource != nullptr)
            {
                return resource;
            }

            resource = new T();
            if (FAILED(resource->Load(path)))
            {
                MessageBox(nullptr, L"Resource Load Failed!", L"ERROR", MB_OK);
                delete resource;
                return nullptr;
            }

            resource->SetName(name);
            resource->SetPath(path);
            mResources.insert(make_pair(name, resource));

            return resource;
        }

        template<typename T>
        static void Insert(const wstring& name, T* resource)
        {
            resource->SetName(name);
            mResources.insert(make_pair(name, resource));
        }

        static void Release()
        {
            for (auto iter : mResources)
            {
                delete iter.second;
                iter.second = nullptr;
            }
        }

    private:
        static map<wstring, JSHResource*> mResources;
    };
}