#ifndef RECTH
#define RECTH
#include"Point.h"
class Rect:public Point{
private:
	int d;
	int w;
public:
	int getd()const{return d;}
	int getw()const{return w;}
	void changed(int ww){w=ww;}
	void changew(int dd){d=dd;}
	Rect(){}
	Rect(const int& x,const int& y,const int& d,const int&w):Point(x,y),d(d),w(w){}
	Rect(const Point& p1,const Point& p2):Point(p1.getx(),p1.gety()){
		d=p2.getx()-p1.getx();
		w=p2.gety()-p1.gety();
	}
	int getArea()const{
		return d*w;
	}
};
#endif