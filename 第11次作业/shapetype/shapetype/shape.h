#ifndef SHAPE
#define SHAPE
#include<iostream>
#include<cmath>
using namespace std;
#define PI acos(-1)
class Shape{
private:
	float a,b;
public:
	float getArea(){
		return a*b;
	}
	float getPerim(){
		return a+b;
	}
};
class Rectangle:public Shape{
private:
	float width,height;
public:
	Rectangle(const float& width,const float &height):width(width),height(height){}
	float getArea(){
		return width*height;
	}
	float getPerim(){
		return 2*(width+height);
	}
};
class Circle:public Shape{
private:
	float r;
public:
	Circle(const float& radius):r(radius){}
	float getArea(){
		return (r*r)*PI;
	}
	float getPerim(){
		return 2*PI*r;
	}
};
#endif