//Expression tree

#include<stdio.h>
#include<malloc.h>
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

void inpost(char iexp[],char rexp[])
{
    int i=0,k=0;
    char ch;
    st.top=-1;
    for(i=0;iexp[i]!='\0';i++)
    {
              switch(iexp[i])
              {
                            case '(' : push(iexp[i]);
                                       break;
                            case '*' : case '/' : if(isempty())push(iexp[i]);
                                                  else
                                                  {
                                                  ch=pop();
                                                  if((ch=='*')||(ch=='/'))
                                                  {
                                                     rexp[k]=ch;
                                                     k++;
                                                     push(iexp[i]);
                                                  }
                                                  if((ch=='+')||(ch=='-')||(ch=='('))
                                                  {
                                                     push(ch);
                                                     push(iexp[i]);
                                                  }
                                                  }
                                                  break;
                            case '+' : case '-' : if(isempty())push(iexp[i]);
                                                  else
                                                  {
                                                  ch=pop();
                                                  while((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/'))
                                                  {
                                                     rexp[k]=ch;
                                                     k++;
                                                     if(isempty())break;
                                                     else ch=pop();   
                                                  }
                                                  if(ch=='(')push(ch);
                                                  push(iexp[i]);
                                                  }
                                                  break;
                            case ')' : ch=pop();
                                       while(ch!='(')
                                       {
                                                     rexp[k]=ch;
                                                     k++;
                                                     ch=pop();
                                       }
                                       break;
                            default : rexp[k]=iexp[i];
                                      k++;
                                      break;
              }
    }
    while(!isempty())
    {
         rexp[k]=pop();
         k++;
    }
    rexp[k]='\0';
}

struct bst
{
       char data;
       struct bst *left,*right;
};

void inorder(struct bst *T)
{
     if(T==NULL) printf("\nEmpty tree");
     else
     {
         if(T->left!=NULL)inorder(T->left);
         printf("%c\t",T->data);
         if(T->right!=NULL)inorder(T->right);
     }
}
 
void preorder(struct bst *T)
{
     if(T==NULL) printf("\nEmpty tree");
     else
     {
         printf("%c\t",T->data);
         if(T->left!=NULL)preorder(T->left);
         if(T->right!=NULL)preorder(T->right);
     }
}

void postorder(struct bst *T)
{
     if(T==NULL) printf("\nEmpty tree");
     else
     {
         if(T->left!=NULL)postorder(T->left);
         if(T->right!=NULL)postorder(T->right);
         printf("%c\t",T->data);         
     }
} 

int main()
{
     int  i,k=-1;
     struct bst **T;
          T=(struct bst**) malloc(sizeof(struct bst*)*10);
          for(i=0;i<10;i++)
              T[i]=NULL;
     char iexp[100];
     char rexp[100];
          printf("\nEnter the expression : \n");
          scanf("%s",&iexp);
          inpost(iexp,rexp);
          printf("\nThe postfix expression is %s",rexp);
          for(i=0;rexp[i]!='\0';i++)
          {
                 switch(rexp[i])
                 {
                                case '+':case '-':case '*':case '/':
                                     {
                                              struct bst *temp;
                                              temp=(struct bst*) malloc(sizeof(struct bst));
                                              temp->data=rexp[i];
                                              temp->left=NULL;
                                              temp->right=NULL;
                                              temp->right=T[k];
                                              T[k]=NULL;
                                              k--;
                                              temp->left=T[k];
                                              T[k]=temp;
                                     }break;
                                
                                default :
                                        {
                                              k++;
                                              struct bst *temp;
                                              temp=(struct bst*) malloc(sizeof(struct bst));
                                              temp->data=rexp[i];
                                              temp->left=NULL;
                                              temp->right=NULL;
                                              T[k]=temp;
                                        }break;
                 }
          }
          printf("\n");
          preorder(T[k]);
          printf("\n");
          inorder(T[k]);
          printf("\n");
          postorder(T[k]);
          printf("\n");
          system("pause");
          return 0;
}           
