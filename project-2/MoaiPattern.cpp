#include "MoaiPattern.h"
#include "Time.h"
#include "Sound.h"
#include "JSHResourcemng.h"

namespace JSH
{

    MoaiPattern::MoaiPattern()
    {   
    }
    MoaiPattern::~MoaiPattern()
    {
    }
    void MoaiPattern::Initialize()
    {
        MoaiNPC::Initialize();
    }
    void MoaiPattern::Update()
    {
        MoaiNPC::Update();
    }
    void MoaiPattern::Render(HDC hdc)
    {
        MoaiNPC::Render(hdc);
    }
}