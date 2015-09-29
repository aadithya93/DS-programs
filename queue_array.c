#include<stdio.h>
#define MAX 5

struct queue
{
	int a[MAX];
	int front,rear;
};

int isempty(struct queue q)
{
	if(q.rear==q.front-1)return 1;
	return 0;
}

int isfull(struct queue q)
{
	if(q.rear==MAX-1)return 1;
	return 0;
}

struct queue enqueue(struct queue q)
{
	if(isfull(q))printf("\nQueue overflow!!");
	else
	{
		q.rear++;
		printf("\nEnter value : ");
		scanf("%d",&q.a[q.rear]);
	}
	return q;
}

struct queue dequeue(struct queue q)
{
	if(isempty(q))printf("\nQueue is empty!!");
	else
	{
		q.front++;
	}
	return q;
}

void display(struct queue q)
{
	int i;
	if(isempty(q))printf("\nEmpty queue");
	else
	{
		printf("\nThe queue is : \n");
		for(i=q.front;i<=q.rear;i++)
			printf("%d\t",q.a[i]);
	}
}

int main()
{
	struct queue q;
		q.front=0;
		q.rear=-1;
	int	ch;
	do
	{
		printf("\n\n\t\t--------QUEUE ARRAY OPERATIONS----------\n");
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	q=enqueue(q);
				break;
			case 2:	q=dequeue(q);
				break;
			case 3:	display(q);
				break;
			case 4: return 0;
			default:printf("\nWrong choice");
		}
	}while(5);
}

