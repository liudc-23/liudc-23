#include<iostream>
class animal
{
public:
	int age;
};
class dog:public animal{
public:
	void Setage(int n){
		age=n;
	}
};
int main()
{
	dog a;
	a.Setage(4);
	return 0;
}