#pragma once

struct DrawParam
{
	DrawParam(CDCHandle& d, RECT m, RECT v):dc(d), rectMap(m), rectView(v){}
	CDCHandle& dc;
	RECT& rectMap;
	RECT& rectView;
	float scale;
    
};

//Point Real2Show(Point pR, RECT rR, RECT rV){
//    
//}
//Rect RECT2Rect(RECT r){
//	return Rect(r.left, r.top, r.bottom-r.top, )
//}

UINT DistanceX(Point x, Point y);

UINT DistanceY(Point x, Point y);