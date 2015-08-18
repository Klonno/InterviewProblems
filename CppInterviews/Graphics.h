#pragma once

struct Line
{
    POINT start;
    POINT end;
};

class CGraphics
{
public:
    CGraphics();
    virtual ~CGraphics();

    BOOL PointInRect(POINT pt, RECT rect);
    BOOL LineIntersect(Line line1, Line line2);

    int CountHighBits(int input);
};

