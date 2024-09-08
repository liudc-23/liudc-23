#ifndef POINTH
#define POINTH
#include<math.h>
#include<iostream>
using namespace std;
class Point{
private:
	int x;
	int y;
public:
	int getx()const{return x;}
	int gety()const{return y;}
	void changex(int xx){x=xx;}
	void changey(int yy){y=yy;}
	Point(const int& x,const int& y):x(x),y(y){}
	Point(){}
	float dist(const Point& p)const{
		return sqrt( (float) ( (p.x-x)*(p.x-x)+(p.gety()-y)*(p.gety()-y) ) );
	}
};
#endif