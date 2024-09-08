#ifndef CUBOIDH
#define CUBOIDH
#include"Rect.h"
class Cuboid:public Rect{
private:
	int h;
public:
	int geth(){return h;}
	void changeh(int hh){h=hh;}
	Cuboid(const int& x, const int& y, const int& d, const int& w, const int& h):Rect(x,y,d,w),h(h){}
	Cuboid(Rect& r,int& h):Rect(r),h(h){}
	int getVol()const{
		return getArea()*h;
	}
	int getCuArea()const{
		return getd()*h*2+getw()*h*2+getArea()*2;
	}
};
#endif