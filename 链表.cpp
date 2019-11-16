#include<bits/stdc++.h>
using namespace std;
struct student
{
	int num;
	float score;
	struct student *next;
};

void create()
{
	int num;
	float score;
	struct student *head,*p,*tail;
	head=NULL;tail=NULL;
	scanf("%d%f",&num,&score);
	while(num)
	{
		p=(struct student*) malloc(sizeof(student));
		p->num=num;
		p->score=score;
		if(head==NULL) head=p;
		else tail->next=p->next;
		tail=p;
		scanf("%d%f",&num,&score);
	}
	printf("%x",head);
}


int main()
{
	struct student *head;
	create();
}

