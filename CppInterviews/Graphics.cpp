#include "stdafx.h"
#include "Graphics.h"


CGraphics::CGraphics()
{
}


CGraphics::~CGraphics()
{
}

BOOL CGraphics::PointInRect(POINT pt, RECT rect)
{
    BOOL inRect = false;

    if (pt.x > rect.left && 
        pt.x < rect.right &&
        pt.y > rect.top &&
        pt.y < rect.bottom)
        inRect = true;
    return inRect;
}

int CGraphics::CountHighBits(int input)
{
    int numbits = sizeof(int) * 8; // sizeof returns byte count, multiple bytes times 8 bits
    int bitcounter, i;

    for (i = 0, bitcounter = 0; i < numbits; ++i, input >>= 1)
    {
        if (input & 0x01)
        {
            ++bitcounter;
        }
    }
    return bitcounter;
}



BOOL LineIntersect(Line line1, Line line2)
{
   return FALSE;
}