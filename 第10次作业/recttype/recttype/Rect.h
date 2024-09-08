#ifndef _RECT_H_
#define _RECT_H_
#include<iostream>
using namespace std;
class Rect{
private:
	float top,bottom,left,right;
public:
	void setTop(const float& t) { top = t; }
    void setLeft(const float& l) { left = l; }
    void setBottom(const float& b) { bottom = b; }
    void setRight(const float& r) { right = r; }

	float gettop(){return top;}
	float getbottom(){return bottom;}
	float getleft(){return left;}
	float getright(){return right;}

	Rect(const float&top1,const float&left1,const float&bottom1,const float&right1):
		top(top1),bottom(bottom1),left(left1),right(right1){}
	Rect():top(0),left(0),bottom(0),right(0){}
	float getArea()const {
		return ((top-bottom)*(right-left));
	}
};
#endif