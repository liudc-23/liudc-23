#include<stdio.h>
#include<stdlib.h>
int main()
{
	void sort(int *mat[100],int m);
	void unite(int *a[100],int am,int *b[100],int bm,int*c[200]);
	int am=0,bm=0;
	int a[100][2],b[100][2];
	int *c[200]={0};
	int *sortedA[100],*sortedB[100];
	for(int i=0;;i++){
		scanf("%d %d",&a[i][0],&a[i][1]);
		am++;
		if(a[i][0]==0)break;
	}
	for(int i=0;i<am;i++)
		sortedA[i]=a[i];
	for(int i=0;;i++){
		scanf("%d %d",&b[i][0],&b[i][1]);
		bm++;
		if(b[i][0]==0)break;//ע��0Ҳ�������ˣ�����������ڵ�һ��
	}
	for(int i=0;i<bm;i++)
		sortedB[i]=b[i];
	sort(sortedA,am);
	sort(sortedB,bm);
	unite(sortedA,am,sortedB,bm,c);
	for(int i=0;i<am+bm;i++)printf("(%d,%d)\n",*c[i],*(c[i]+1));
}
void sort(int *mat[100],int m)//ѡ������
{
	int j=0,min=0;
	int *t=0;
	for(int i=0;i<m-1;i++){
		min=i;
		for(j=i+1;j<m;j++){
			if(*mat[j]<*mat[i])//�жϱ�׼Ϊx
				min=j;
		}//��ʱk��Ӧ������Сֵ
		if(min!=i){
			t=mat[i];
			mat[i]=mat[min];
			mat[min]=t;
		}//�����е�ַ
	}
}
void unite(int *a[100],int am,int *b[100],int bm,int *c[200])
{
	for(int i=0;i<am;i++)
		c[i]=a[i];
	for(int i=0;i<bm;i++)
		c[i+am]=b[i];
	sort(c,am+bm);
}