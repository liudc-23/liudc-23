#include<stdio.h>
#include<stdlib.h>
typedef struct tagNODE
{
	int m,n;
	int data;
	struct tagNODE *next;
}NODE,*linklist;
void destory(linklist *mat);
void sort(linklist a);
void Del(linklist a);
void sum(linklist a,linklist b);
void getmat(linklist *mat,int num);
int count(linklist a);
void output(linklist a,int i);
int count(linklist a)
{
	int cnt=0;
	linklist p=a->next;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;
	}
	return cnt;
}
void output(linklist a,int i)//�����i��Ԫ��
{
	linklist p=a;
	for(;i>0;i--){
		p=p->next;
	}
	printf("%d,%d,%d",p->data,p->m,p->n);
}
void getmat(linklist *mat,int num)//numΪ������ֻ��10��,numΪ�ڵ���
{
	int col=1,row=1;
	linklist s,p;
	*mat=(linklist)malloc(sizeof(NODE));
	p=*mat;//mat��Ϊͷ�ڵ㣬��������û�����롣
	(*mat)->next=NULL;
	for(;num>0;num--){
		s=(linklist)malloc(sizeof(NODE));
		if(row==1)
			scanf("%d",&(s->data));
		else
			scanf(",%d",&(s->data));
		s->m=col;
		s->n=row;
		row++;
		if(row>10){
			col++;
			row=1;
		}
		p->next=s;
		p=s;
	}
	p->next=NULL;
}
int main()
{
	linklist a,b;
	int cnt=0,i=0;
	getmat(&a,100);
	getmat(&b,100);
	sum(a,b);
	Del(a);
	sort(a);
	cnt=count(a);
	if(cnt%2==0)
		i=cnt/2;
	else 
		i=cnt/2+1;
	output(a,i);
	destory(&a);
	destory(&b);
	return 0;
}
void destory(linklist *mat)
{
	linklist temp,p=*mat;
	while(p!=NULL){
		temp=p->next;
		free(p);
		p=temp;
	}
	*mat=NULL;//ԭ��ָ��������ͷ���Ϊ��
}
void sum(linklist a,linklist b)
{//��;������a��
	linklist pa=a->next;
	linklist pb=b->next;
	while(pa!=NULL&&pb!=NULL)
	{
		pa->data=pa->data+pb->data;
		pa=pa->next;
		pb=pb->next;
	}
}
void Del(linklist a)//ɾ������Ϊ0�Ľڵ�
{
	linklist q=a,p=a->next;
	while(p!=NULL&&q!=NULL){//q��p��ǰһ�����
		if(p->data==0){
			q->next=p->next;
			free(p);
			p=q->next;
		}
		else{
			q=p;
			p=p->next;
		}
	}
}
void sort(linklist a)//����a
{
	linklist p,q;
	int t;
	q=a->next;
	p=q->next;
	while(q->next!=NULL){//q��p��ǰһ���ڵ�/����ѡ������
		while(p!=NULL){
			if(p->data>q->data){//�����򽻻�
				t=p->data;
				p->data=q->data;
				q->data=t;

				t=p->m;
				p->m=q->m;
				q->m=t;

				t=p->n;
				p->n=q->n;
				q->n=t;
			}
			if(p->data==q->data){
				if(p->n>q->n){
					t=p->data;
					p->data=q->data;
					q->data=t;

					t=p->m;
					p->m=q->m;
					q->m=t;

					t=p->n;
					p->n=q->n;
					q->n=t;
				}
				if(p->n==q->n){
					if(p->m>q->m){
						t=p->data;
						p->data=q->data;
						q->data=t;

						t=p->m;
						p->m=q->m;
						q->m=t;

						t=p->n;
						p->n=q->n;
						q->n=t;
					}
				}
			}
			p=p->next;
		}
		q=q->next;
		p=q->next;
	}
}
