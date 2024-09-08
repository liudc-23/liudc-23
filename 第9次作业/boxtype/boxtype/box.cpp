#include<stdio.h>
#include<iostream>
using namespace std;
class Box
{
private:
	int a;
public:
	Box(int aa):a(aa){}
	Box(Box &bb):a(bb.a){}
	int getv(){
		return a*a*a;
	}
	int getS(){
		return 6*a*a;
	}
};
int main()
{
	int a;
	cin>>a;
	Box box(a);
	cout<<box.getv()<<" "<<box.getS()<<endl;
	return 0;
}