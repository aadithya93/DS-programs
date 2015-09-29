#include<stdio.h>
#define MAX 100

struct stack
{
	int a[MAX];
	int top;
};

int isempty(struct stack st)
{
	if(st.top==-1)return 1;
	return 0;
}

int isfull(struct stack st)
{
	if(st.top==MAX)return 1;
	return 0;
}

struct stack push(struct stack st)
{
	if(isfull(st))printf("\nStack overflow!!");
	else
	{
		st.top++;
		printf("\nEnter value : ");
		scanf("%d",&st.a[st.top]);
	}
	return st;
}

struct stack pop(struct stack st)
{
	if(isempty(st))printf("\nStack is empty!!");
	else
	{
		st.top--;
	}
	return st;
}

struct stack peekpop(struct stack st)
{
	if(isempty(st))printf("\nStack is empty!!");
	else
	{
		printf("\nThe top value is %d",st.a[st.top]);
		st.top--;
	}
	return st;
}

void display(struct stack st)
{
	int i;
	if(isempty(st))printf("\nEmpty stack");
	else
	{
		printf("\nThe stack is : \n");
		for(i=st.top;i>=0;i--)
			printf("\n%d",st.a[i]);
	}
}

int main()
{
	struct stack st;
		st.top=-1;
	int	ch;
	do
	{
		printf("\n\n\t\t--------STACK ARRAY OPERATIONS----------\n");
		printf("\n1.Push\n2.Pop\n3.Peek and Pop\n4.Display\n5.Exit\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	st=push(st);
				break;
			case 2:	st=pop(st);
				break;
			case 3:	st=peekpop(st);
				break;
			case 4:	display(st);
				break;
			case 5: return 0;
			default:printf("\nWrong choice");
		}
	}while(5);
}
