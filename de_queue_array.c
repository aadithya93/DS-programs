// Doubl ended quees (array)

#include<stdio.h>
#define MAX 5

struct queue
{
	int a[MAX];
	int front,rear;
};

int isempty(struct queue q)
{
	if((q.rear==-1)&&(q.front==-1))return 1;
	return 0;
}

int isfull(struct queue q)
{
	if((q.rear+1)%MAX==q.front)return 1;
	return 0;
}

struct queue enqueue(struct queue q)
{
	if(isfull(q))printf("\nQueue overflow!!");
	else
	{
		if(isempty(q))
		{
			q.rear=0;
			q.front=0;
		}
		else
			q.rear=(q.rear+1)%MAX;
		printf("\nEnter value : ");
		scanf("%d",&q.a[q.rear]);
	}
	return q;
}


struct queue de_enqueue(struct queue q)
{
	if(isfull(q))printf("\nQueue overflow!!");
	else
	{
		if(isempty(q))
		{
			q.rear=0;
			q.front=0;
		}		
		else
			q.front=(q.front-1+MAX)%MAX;
		printf("\nEnter value : ");
		scanf("%d",&q.a[q.front]);
	}
	return q;
}

struct queue dequeue(struct queue q)
{
	if(isempty(q))printf("\nQueue is empty!!");
	else
	{
		if(q.front==q.rear)
		{
			q.rear=q.front=-1;		
		}
		else
			q.front=(q.front+1)%MAX;
	}
	return q;
}

struct queue de_dequeue(struct queue q)
{
	if(isempty(q))printf("\nQueue is empty!!");
	else
	{
		if(q.front==q.rear)
		{
			q.rear=q.front=-1;		
		}
		else
			q.rear=(q.rear-1+MAX)%MAX;
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
		if(q.front<=q.rear)
		{
			for(i=q.front;i<=q.rear;i++)
				printf("%d\t",q.a[i]);
		}
		else
		{
			
			for(i=q.front;i<MAX;i++)
				printf("%d\t",q.a[i]);
			for(i=0;i<=q.rear;i++)
				printf("%d\t",q.a[i]);
		}
	}
}

int main()
{
	struct queue q;
		q.front=-1;
		q.rear=-1;
	int	ch;
	do
	{
		printf("\n\n\t\t--------DOUBLE ENDED QUEUE ARRAY OPERATIONS----------\n");
		printf("\n1.Enqueue at rear\n2.Enqueue at front\n3.Dequeue at front\n4.Dequeue at rear\n5.Display\n6.Exit\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	q=enqueue(q);
				break;
			case 2:	q=de_enqueue(q);
				break;
			case 3:	q=dequeue(q);
				break;
			case 4:	q=de_dequeue(q);
				break;
			case 5:	display(q);
				break;
			case 6: return 0;
			default:printf("\nWrong choice");
		}
	}while(5);
}

