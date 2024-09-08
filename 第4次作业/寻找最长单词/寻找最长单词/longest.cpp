#include<stdio.h>
int main()
{void max(char a[]);
char a[1000]={0};
gets(a);
max(a);
return 0;
}
void max(char a[])
{
int cnt=0,place=0;
int max=0;
for(int i=0;i<1000;i++){
	if(a[i]!=' '&&a[i]!=','&&a[i]!='.'){
		cnt++;
	}
	if(a[i]==' '||a[i]==','||a[i]=='.'){
		if(cnt>max){
			max=cnt;
			place=i;//æÕ «÷∏’Î
		}
		cnt=0;
	}
	if(a[i]=='.'){
		break;
	}
}
for(int i=place-max;i<place;i++)printf("%c",a[i]);
}
		




	
	
