#pragma once

struct DrawParam
{
	DrawParam(CDCHandle& d, RECT m, RECT v):dc(d), rectMap(m), rectView(v){}
	CDCHandle& dc;
	RECT& rectMap;
	RECT& rectView;
	float scale;
};

//Rect RECT2Rect(RECT r){
//	return Rect(r.left, r.top, r.bottom-r.top, )
//}