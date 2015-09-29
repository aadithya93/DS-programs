//Balancing paranthesis

#include<stdio.h>
#define MAX 100

struct stack
{
	char a[MAX];
	int top;
}st;

int isempty()
{
	if(st.top==-1)return 1;
	return 0;
}

int isfull()
{
	if(st.top==MAX)return 1;
	return 0;
}

void push(char c)
{
	if(isfull())printf("\nStack overflow!!");
	else
	{
		st.top++;
		st.a[st.top]=c;;
	}
}

char pop()
{
	if(isempty())printf("\nStack is empty!!");
	else
	{
		st.top--;
	}
	return st.a[st.top+1];
}

int main()
{
    int i=0;
    char ch;
    st.top=-1;
    char exp[100];
    printf("\nEnter the expression : \n");
    scanf("%s",&exp);
    for(i=0;exp[i]!='\0';i++)
    {
              switch(exp[i])
              {
                            case '[' : case '{' : case '(' : push(exp[i]);
                                                             break;
                            case ']' : case '}' : case ')' : ch=pop();
                                                             if(((exp[i]==']')&&(ch=='['))||((exp[i]=='}')&&(ch=='{'))||((exp[i]==')')&&(ch=='(')))break;
                                                             else push(exp[i]);
                                                             break;
                            default : break;
              }
    }
    if(isempty())printf("\nThe expression is valid!");
    else  printf("\nThe expression is not valid!");
    getch();
    return 0;
}
