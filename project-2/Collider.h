#pragma once
#include "Component.h"

namespace JSH
{
    using namespace math;

    class Collider : public Component
    {
    public:
        Collider();
        virtual ~Collider();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

        virtual void OnColliderEnter(Collider* other);
        virtual void OnColliderStay(Collider* other);
        virtual void OnColliderExit(Collider* other);

        vector2 GetSize()
        {
            return mSize;
        }
        void SetSize(vector2 size)
        {
            mSize = size;
        }

        vector2 GetOffset()
        {
            return mOffset;
        }
        void SetOffset(vector2 offset)
        {
            mOffset = offset;
        }
        vector2 GetPosition() 
        { 
            return mPosition; 
        }
        void SetPosition(vector2 position)
        {
            mPosition = position;
        }
        UINT GetCollisionNumber()
        { 
            return mCollisionNumber;
        }

    private:
        static UINT mCollisionCount;

        vector2 mSize;
        vector2 mOffset;
        vector2 mPosition;

        UINT mCollisionNumber;
        bool mbIsCollision;

        static bool mColTrigger;
    };
}