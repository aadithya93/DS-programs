#include<stdio.h>
#include<malloc.h>

struct stack
{
	int data;
	struct stack *next;
};

int isempty(struct stack *top)
{
	if(top==NULL)return 1;
	return 0;
}

struct stack* push(struct stack *top)
{
	struct stack *temp;
	temp=(struct stack*) malloc(sizeof(struct stack));
	printf("\nEnter value : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(top==NULL)top=temp;
	else
	{
		temp->next=top;
		top=temp;
	}
	return top;
}

struct stack* pop(struct stack *top)
{
	if(isempty(top))printf("\nStack is empty!!");
	else
	{
		struct stack *temp;
		temp=(struct stack*) malloc(sizeof(struct stack));
		temp=top;
		top=top->next;
		free(temp);
	}
	return top;
}

struct stack* peekpop(struct stack *top)
{
	if(isempty(top))printf("\nStack is empty!!");
	else
	{
		struct stack *temp;
		temp=(struct stack*) malloc(sizeof(struct stack));
		temp=top;
		top=top->next;
		printf("\nThe top element is %d",temp->data);
		free(temp);
	}
	return top;
}

void display(struct stack *top)
{
	if(isempty(top))printf("\nEmpty stack");
	else
	{
		printf("\nThe stack is : \n");
		struct stack *temp;
		temp=(struct stack*) malloc(sizeof(struct stack));
		temp=top;
		while(temp!=NULL)
		{
			printf("\n%d",temp->data);
			temp=temp->next;
		}
	}
}

int main()
{
	struct stack *top;
		top=NULL;
	int	ch;
	do
	{
		printf("\n\n\t\t--------STACK ARRAY OPERATIONS----------\n");
		printf("\n1.Push\n2.Pop\n3.Peek and Pop\n4.Display\n5.Exit\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	top=push(top);
				break;
			case 2:	top=pop(top);
				break;
			case 3:	top=peekpop(top);
				break;
			case 4:	display(top);
				break;
			case 5: return 0;
			default:printf("\nWrong choice");
		}
	}while(5);
}
