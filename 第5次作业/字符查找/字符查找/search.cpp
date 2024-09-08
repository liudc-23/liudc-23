#include<stdio.h>
#include<string.h>
int main()
{
	int search(char *a,char *b);
	char *p[]={"C",
				"C++",
				"Python",
				"Java",
				"Basic",
				"C#",
				"PHP",
				"Javascript ",
				"SQL",
				"Ruby",
				"Matlab",
				"Go",
				"Perl",
				"R",
				"Fortran",
				"Pascal",
				"Swift",
				};
	char ch[10]={0};
	char *pch=ch;
	scanf("%s",ch);
	for(int i=0;i<17;i++){
		if(search(p[i],ch))
			printf("%s\n",p[i]);
	}
	return 0;
}
int search(char *a,char *b)//判断b是不是a的字串
{
	int i=0,j=0,k=0;
	int lena=strlen(a);
	int lenb=strlen(b);
	for(i=0;i<lena;i++){
		j=i;
		while(a[j]==b[k]){//
			k++;
			j++;				//用j来代替i递增，相当于在找到等于b[0]的a[i]后循环判断在i后面的区间内是否全等于字符串b
		}
		if(k>=lenb)
			return 1;
		k=0;//复原
	}
		return 0;
}

				
			
