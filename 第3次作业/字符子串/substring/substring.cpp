#include<stdio.h>
int main()
{int i,n=0;
	char ar[257];
scanf("%s",ar);
for(i=0;i<255;i++)
	if(ar[i]=='a'&&ar[i+1]=='b'&&ar[i+2]=='a')
		n++;
printf("%d",n);
return 0;
}