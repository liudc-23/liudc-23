#include<stdio.h>
#include<stdlib.h>
typedef struct S
{
	int num;
	struct S *next;
}stu,*link;
void makelist(link *L,int N);
void destory(link *L,int N);
int main()
{
	int N,m;
	int cnt=0;
	link L;
	link p,q;
	scanf("%d %d",&N,&m);
	makelist(&L,N);
	/*p=L->next;
	for(int i=0;i<N+1;i++){
		printf("%d\n",p->num);
			p=p->next;
	}*/
	q=L;
	p=q->next;
	if(m==1){ 
		printf("%d",N);//mΪ1ʱɾ����һ���ڵ��ѭ�����ѣ����ܷ���ͷ�ڵ��������
		destory(&L,N);
	}
	else{
		while(1){
			cnt++;
			if(cnt==m){//ɾ���ڵ�
				q->next=p->next;
				free(p);
				p=q->next;
				cnt=0;
			}
			else{//ע��ɾ���ڵ����Ҫ���ƶ�ָ�룬ֻ��ûɾ��ʱ���ƶ�
				q=p;
				p=p->next;
			}//ע�⣺ֻʣһ���ڵ�ʱp->next����;ָ��
			if(p->next==q) break;//ʣ�����ڵ�ʱ�˳�
		}
		if(m%2==0)
			printf("%d",p->num);
		else
			printf("%d",q->num);
		free(p);
		free(q);
	}
	return 0;
}
void makelist(link *L,int N)
{
	link p,s;
	(*L)=(link)malloc(sizeof(stu));
	p=(*L);
	p->next=NULL;
	for(int i=1;i<=N;i++){
		s=(link)malloc(sizeof(stu));
		s->num=i;
		p->next=s;
		p=s;
	}
	p->next=(*L)->next;//ѭ������
}
void destory(link *L,int N)
{
	link p=*L;
	link q;
	for(int i=0;i<N;i++){
		q=p->next;
		free(p);
		p=q;
	}
	*L=NULL;
}