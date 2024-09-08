#include<stdio.h>
#include<string.h>
int main()
{char a[1000][1000]={0};
int equal=0,max=0;
int num[1000]={0};
	for(int i=0;i<1000;i++){
		scanf("%s",a[i]);
		if(strcmp(a[i],"end")==0)break;
	}
for(int i=0;;i++){
	for(int j=i+1;;j++){
		if(strcmp(a[i],a[j])==0)equal++;
		if(strcmp(a[j],"end")==0)break;
	}
	num[i]=equal;
	equal=0;
	if(strcmp(a[i+1],"end")==0)break;
}
for(int i=0;i<1000;i++){
	if(num[i]>max)max=num[i];
}
for(int i=0;i<1000;i++)
	if(num[i]==max)printf("%s %d\n",a[i],max+1);
return 0;
}


