#include<stdio.h>
int main()
{
	char ch;
		int offset;
		int result;
		scanf("%d %c",&offset,&ch);
		result=offset+ch;
		printf("%c",result);
		return 0;
}