#include "stdafx.h"
#include "DrawUtil.h"

UINT DistanceX( Point x, Point y )
{
    return abs(x.X - y.X);
}

UINT DistanceY( Point x, Point y )
{
    return abs(x.Y - y.Y);
}
