#include<stdio.h>
#include<malloc.h>
#define MAX 100

struct queue
{
	int data;
	struct queue *next;
};

int isempty(struct queue *front)
{
	if(front==NULL)return 1;
	return 0;
}

struct queue* enqueue(struct queue *rear)
{
	struct queue *temp;
	temp=(struct queue*) malloc(sizeof(struct queue));
	printf("\nEnter value : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(rear==NULL)rear=temp;
	else 
	{
		rear->next=temp;
		rear=temp;
	}
	return rear;
}

struct queue* dequeue(struct queue *front)
{
	if(isempty(front))printf("\nQueue is empty!!");
	else
	{
		struct queue *temp;
		temp=(struct queue*) malloc(sizeof(struct queue));
		temp=front;
		front=front->next;
		free(temp);
	}
	return front;
}

void display(struct queue *front)
{
	int i;
	if(isempty(front))printf("\nEmpty queue");
	else
	{
		printf("\nThe queue is : \n");
		struct queue *temp;
		temp=(struct queue*) malloc(sizeof(struct queue));
		temp=front;
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}

int main()
{
	struct queue *front,*rear;
		front=NULL;
		rear=NULL;
	int	ch;
	do
	{
		printf("\n\n\t\t--------QUEUE LINKED LIST OPERATIONS----------\n");
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	if(rear==NULL)
				{
					rear=enqueue(rear);
					front=rear;
				}	
				else rear=enqueue(rear);
				break;
			case 2: front=dequeue(front);
				if(front==NULL) rear=NULL;
				break;
			case 3:	display(front);
				break;
			case 4: return 0;
			default:printf("\nWrong choice");
		}
	}while(5);
}

