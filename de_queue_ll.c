//Double ended queue ( linked list)

#include<stdio.h>
#include<malloc.h>
#define MAX 100

struct queue
{
	int data;
	struct queue *next;
};

int isempty(struct queue *rear)
{
	if(rear==NULL)return 1;
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

struct queue* de_enqueue(struct queue *front)
{
	struct queue *temp;
	temp=(struct queue*) malloc(sizeof(struct queue));
	printf("\nEnter value : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(front==NULL)front=temp;
	else 
	{
		temp->next=front;
		front=temp;
	}
	return front;
}

struct queue* dequeue(struct queue *front,struct queue *rear)
{
	if(isempty(front))printf("\nQueue is empty!!");
	else
	{
		struct queue *temp;
		temp=(struct queue*) malloc(sizeof(struct queue));
		temp=front;
		if(front==rear)front=NULL;
		if(front!=NULL)front=front->next;
		free(temp);
	}
	return front;
}

struct queue* de_dequeue(struct queue *rear,struct queue *front)
{
	if(isempty(rear))printf("\nQueue is empty!!");
	else
	{
		struct queue *temp;
		temp=(struct queue*) malloc(sizeof(struct queue));
		temp=front;
		do
		{
            		if(temp->next!=front)
            		{
              			if(temp->next->next==front)
              			{
                 			temp->next=front;
                 			break;
              			}
            		}
			else
			{
				temp=NULL;
			}
            		if(temp!=NULL)temp=temp->next;
        	}while((temp!=front)&&(temp!=NULL));
        	free(rear);
       		rear=temp;
	}
	return rear;
}

void display(struct queue *front)
{
	if(isempty(front))printf("\nEmpty queue");
	else
	{
		printf("\nThe queue is : \n");
		struct queue *temp;
		temp=(struct queue*) malloc(sizeof(struct queue));
		temp=front;
		do
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}while(temp!=front);
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
		printf("\n\n\t\t--------DOUBLE ENDED QUEUE LINKED LIST OPERATIONS----------\n");
		printf("\n1.Enqueue at rear\n2.Enqueue at front\n3.Dequeue at front\n4.Dequeue at rear\n5.Display\n6.Exit\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	if(rear==NULL)
				{
					rear=enqueue(rear);
					front=rear;
					rear->next=front;
				}	
				else 
				{
					rear=enqueue(rear);
					rear->next=front;
				}
				break;
			case 2:	if(front==NULL)
				{
					front=de_enqueue(front);
					rear=front;
					rear->next=front;
				}	
				else 
				{
					front=de_enqueue(front);
					rear->next=front;
				}
				break;
			case 3: front=dequeue(front,rear);
				if(front==NULL) rear=NULL;
				else rear->next=front;
				break;
			case 4: rear=de_dequeue(rear,front);
				if(rear==NULL) front=NULL;
				else rear->next=front;
				break;
			case 5:	display(front);
				break;
			case 6: return 0;
			default:printf("\nWrong choice");
		}
	}while(5);
}

