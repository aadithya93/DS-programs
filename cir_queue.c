//Circular Queue

#include<stdio.h>
#include<conio.h>
#define MAX 5

struct queue
{
	int a[MAX];
	int front,rear;
	int size,capacity;
};

int isempty(struct queue q)
{
	if(q.size==0)return 1;
	return 0;
}

int isfull(struct queue q)
{
	if(q.size==q.capacity)return 1;
	return 0;
}

struct queue enqueue(struct queue q)
{
	if(isfull(q))printf("\nQueue overflow!!");
	else
	{
		if(q.rear==MAX-1)q.rear=-1;
		q.rear++;
		printf("\nEnter value : ");
		scanf("%d",&q.a[q.rear]);
		q.size++;
	}
	return q;
}

struct queue dequeue(struct queue q)
{
	if(isempty(q))printf("\nQueue is empty!!");
	else
	{
		if(q.front==MAX-1) q.front=-1;
		q.front++;
		q.size--;
	}
	return q;
}

void display(struct queue q)
{
	int i,j=q.front;
	if(isempty(q))printf("\nEmpty queue");
	else
	{
        printf("\nThe queue is : \n");
		for(i=0;i<q.size;i++)
		{
			printf("%d\t",q.a[j]);
		    if(j==(q.capacity-1)) j=-1;
		    j++;
		}
	}
}

int main()
{
	struct queue q;
		q.front=0;
		q.rear=-1;
		q.size=0;
		q.capacity=MAX;
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
	getch();
	return 0;
}
