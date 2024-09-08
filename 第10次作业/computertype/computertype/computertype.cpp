#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class CPU;
class RAM;
class CDROM;
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
	void set(int r,int f,float v){
		rank=(Cpurank)r;
		fqucy=f;
		vol=v;
	}
private:
	Cpurank rank;
	int fqucy;
	float vol;
};
class RAM{
public:
	void set(char *a){
		strcpy(type,a);
	}
	void run(){
		cout<<"RAM RUN"<<endl;
		cout<<"RAM type: "<<type<<endl;
	}
	void stop(){
		cout<<"RAM STOP"<<endl;
	}
private:
	char type[20];
};
class CDROM{
public:
	void set(char *a)
	{
		strcpy(type,a);
	}
	void run(){
		cout<<"CDROM RUN"<<endl;
		cout<<"CDROM type: "<<type<<endl;
	}
	void stop(){
		cout<<"CDROM STOP"<<endl;
	}
private:
	char type[20];
};
class Computer{
public:
	Computer(CPU &c,RAM &r,CDROM &o):cpu(c),ram(r),cdrom(o){}
	void run(){
		cout<<"Computer RUN"<<endl;
		cpu.run();
        ram.run();
        cdrom.run();
	}
	void stop(){
		cdrom.stop();
        ram.stop();
        cpu.stop();
		cout<<"Computer STOP"<<endl;
	}
private:
	CPU cpu;
	RAM ram;
	CDROM cdrom;
};
int main()
{
	CPU cpu;
	RAM ram;
	CDROM cdrom;
	int r=0,f=0;
	float v=0;
	char ty[20]={0},ty2[20]={0};
	char buffer[10];
	for(int i=0;i<3;i++){
		cin>>buffer;
		int flag=0;
		if(strcmp(buffer,"CPU")==0){
			cin>>r>>f>>v;
			cpu.set(r,f,v);
			flag=1;
		}
		if(strcmp(buffer,"RAM")==0){
			cin>>ty;
			ram.set(ty);
			flag=1;
		}
		if(strcmp(buffer,"CDROM")==0){
			cin>>ty2;
			cdrom.set(ty2);
			flag=1;
		}
		if(flag==0)
			cout<<"ERROR"<<endl;
	}
	Computer com(cpu,ram,cdrom);
	com.run();
	com.stop();
	return 0;
}