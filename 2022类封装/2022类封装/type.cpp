#include<stdio.h>
#include<iostream>
using namespace std;
class Rectangle{
private:
	float w;
	float l;
public:
	Rectangle(float ll,float ww){
		w=(ww>0)?ww:0;
		l=(ll>0)?ll:0;
	}
	void SetLW(float ll,float ww){
		if(ww>=0)
			w=ww;
		if(ll>=0)
			l=ll;
	}
	float Area(){
		return l*w;
	}
};
class Cuboid:public Rectangle{
private:
	float h;
public:
	Cuboid(float ll,float ww,float hh):Rectangle(ll,ww){
		h=hh;
	}
	void SetHeight(float hh){
		if(hh>=0)
			h=hh;
	}
	float Volume(){
		return h*Area();
	}
};
int main(){
	float w,l,h;
	cin>>l>>w>>h;
	Cuboid a(l,w,h);
	printf("%.3f",a.Volume());
	return 0;
}

