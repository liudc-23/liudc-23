#ifndef circle
#define circle
#include <math.h>
class Circle{
public:
	float getArea(){
		float a=-1;
		return acos(a)*r*r;
	}
	Circle(const float& r){
		this->r=r;
	}
private:
	float r;
};
#endif