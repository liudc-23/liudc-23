#include<stdio.h>
#include<iostream>
using namespace std;
enum Cpurank{P1=1,P2,P3,P4,P5,P6,P7};
class CPU{
public:
	void run(){
		cout<<"CPU RUN"<<endl;
		cout<<"CPU rank: P"<<rank<<endl;
		cout<<"CPU frequency: "<<fqucy<<" MHz"<<endl;
		printf("CPU voltage: %.2f V\n",vol);
	}
	void stop(){
		cout<<"CPU STOP"<<endl; 
	}
	CPU(int r,int fre,float volo){
		rank=(Cpurank)r;
		fqucy=fre;
		vol=volo;
		cout<<"CPU Construct"<<endl;
	}
	~CPU(){
		cout<<"CPU Destroy"<<endl;
	}
private:
	Cpurank rank;
	int fqucy;
	float vol;
};
int main()
{
	int rank;
	int fre;
	float volt;
	cin>>rank>>fre>>volt;
	CPU a(rank,fre,volt);
	a.run();
	a.stop();
	return 0;
}
