#include<stdio.h>
#include<stdlib.h>
typedef struct S
{
	int a;
	int n;
	struct S *next;
}poly,*link;
void makelist(link *L,int N);
void destory(link *L);
void output(link L);
void sum(link L1,link L2,int max);
int max(link L1,link L2);
void sum2(link L1,link L2);
int main()
{
	int M1,M2;
	link L1,L2;
	scanf("%d",&M1);
	makelist(&L1,M1);
	scanf("%d",&M2);
	makelist(&L2,M2);
	//sum(L1,L2,max(L1,L2));
	sum2(L1,L2);
	output(L1);
	destory(&L1);
	destory(&L2);
}
void makelist(link *L,int N)
{
	link p,s;
	*L=(link)malloc(sizeof(poly));
	p=*L;
	for(int i=0;i<N;i++){
		s=(link)malloc(sizeof(poly));
		scanf("%d %d",&(s->a),&(s->n));
		p->next=s;
		p=s;
	}
	p->next=NULL;
}
void destory(link *L)
{
	link p=(*L);
	link q;
	while(p!=NULL){
		q=p->next;
		free(p);
		p=q;
	}
	(*L)=NULL;
}
void output(link L)
{
	link p=L->next;
	while(p!=NULL){
		printf("%d %d\n",p->a,p->n);
		p=p->next;
	}
}
void sum(link L1,link L2,int max)//��ߴδ���
{
	link p,s;
	int nmi=0,sum=0;
	int a[100]={0};
	int cnt=0;
	for(;nmi<=max;nmi++){
		p=L1->next;
		while(p!=NULL){
			if(p->n==nmi){
				sum+=p->a;
			}
			p=p->next;
		}
		s=L2->next;
		while(s!=NULL){
			if(s->n==nmi){
				sum+=s->a;
			}
			s=s->next;
		}
		if(sum!=0){
			a[nmi]=sum;
			cnt++;
		}
		sum=0;
	}
	printf("%d\n",cnt);
	for(int i=0;i<max+1;i++){
		if(a[i]!=0)
			printf("%d %d\n",a[i],i);
	}
}
//ʹ��������ɼӷ���û��������
void sum2(link L1,link L2)
{
	//�ȱ�֤L1�Ǵ������ߵĶ���ʽ��Ȼ���L2����L1����
	link p,q,temp;
	int m1,m2;
	p=L1->next;
	while(p!=NULL){
		q=p;
		p=p->next;
	}
	m1=q->n;
	p=L2->next;
	while(p!=NULL){
		q=p;
		p=p->next;
	}
	m2=q->n;
	if(m1<m2){
		temp=L1->next;
		L1->next=L2->next;
		L2->next=temp;
	}
	//�ٱ��������������ʽ
	int flag=0;
	p=L1->next;
	q=L2->next;
	link sp=L1,sq=L2;//��Ϊǰ��
	while(q!=NULL){
		while(p!=NULL){
			if(q->n==p->n){
				p->a+=q->a;
				flag=1;
				break;
			}
		}
		p=L1;
		if(flag==0){//��q����L1��
			do{
				sp=p;
				p=p->next;
			}while(p->n<q->n);//��ʱ
			sp->next=q;
			sq->next=q->next;//ͬʱ��L2��ɾ������ڵ�
			q->next=p;
		}
		p=L1->next;
		sq=q;
		q=q->next;
		flag=0;
	}
}
int max(link L1,link L2)
{
	link p,q;
	int m1,m2;
	p=L1->next;
	while(p!=NULL){
		q=p;
		p=p->next;
	}
	m1=q->n;
	p=L2->next;
	while(p!=NULL){
		q=p;
		p=p->next;
	}
	m2=q->n;
	return m1>m2?m1:m2;
}
