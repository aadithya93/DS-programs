#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct node
{
	int	data;
    struct node *next;
    struct node *prev;
};

struct node* create(struct node *head)
{
    struct node *p,*c;
    p=(struct node*) malloc(sizeof(struct node));
    int	n,i=0;
	printf("\nEnter number of elements to be added : ");
	scanf("%d",&n);
	do
	{
		c=(struct node*) malloc(sizeof(struct node));
		printf("\nEnter the data : ");
		scanf("%d",&c->data);
		c->next=NULL;
		c->prev=NULL;
		if(head==NULL)
		{
			head=c;
			c->prev=head;
        }
		else
		{
			p->next=c;
			c->prev=p;
        }
		p=c;
        i++;
	}while(i<n);
	return head;
}

void display(struct node *head)
{
  struct node	*p;
	p=(struct node*) malloc(sizeof(struct node));
	p=head;
	if(p!=NULL)
	{
 	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
	p=head;
	while(p->next!=NULL)
            p=p->next;
    while(p!=head)
    {
		printf("%d\t",p->data);
		p=p->prev;
	}
	printf("%d\t",p->data);
    }
}

struct node* make_empty(struct node *head)
{
       while(head->next!=NULL)
       {
                        head=head->next;
                        free(head->prev);
       }
       free(head);
       printf("\nList is empty");
       return NULL;
}

struct node* del(struct node *head,int pos)
{
    int	i=0;
    struct node *c,*p;
    p=(struct node*) malloc(sizeof(struct node));
	c=(struct node*) malloc(sizeof(struct node));
	c=head;
 	while(c!=NULL)
	{
		i++;
		if(i==pos)
		{            
		             if(pos==1)
		             {
			          head=c->next;
			          c->next->prev=head;
			          p=c;
			          free(p);
			          return head;
         		     }
		             else 
		             {
				      c->prev->next=c->next;
				      if(c->next!=NULL)
                           c->next->prev=c->prev;
				      p=c;
			          free(p);
                      return head;
                     }
          }
          c=c->next;
    }
}

struct node* insert(struct node* head,int pos)
{
     int	i=0;
    struct node *p,*c,*temp;
    p=(struct node*) malloc(sizeof(struct node));
	c=(struct node*) malloc(sizeof(struct node));
	temp=(struct node*) malloc(sizeof(struct node));
	printf("\nEnter the data to be inserted : ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;
    c=head;
    while(c!=NULL)
    {
                  i++;
                  if(i==pos)
                  {
                            if(pos==1)
                            {
                                      head=temp;
                                      temp->next=c;
                                      temp->prev=head;
                                      c->prev=temp;
                            }
                            else
                            {
                                temp->prev=c->prev;
                                c->prev->next=temp;
                                temp->next=c;  
                                c->prev=temp;
                            }
                  }
                  p=c;
                  c=c->next;
    }
    if(pos==0)
    {
              p->next=temp;
              temp->prev=p;
    }
    return head;
} 

int locate(struct node* head, int data)
{
    struct node	*p;
    int i=0,flag=0;
   	p=(struct node*) malloc(sizeof(struct node));
	p=head;
 	while(p!=NULL)
	{    	
          i++;
          if(p->data==data) flag=i;
          p=p->next;
    }
	return flag;
}

int count(struct node* head)
{
    struct node	*p;
    int i=0;
   	p=(struct node*) malloc(sizeof(struct node));
	p=head;
 	while(p!=NULL)
	{    	
          i++;
          p=p->next;
    }
	return i;
}

struct node* retrieve(struct node* head, int pos)
{
    struct node	*p,*flag;
    int i=0;
   	p=(struct node*) malloc(sizeof(struct node));
	flag=(struct node*) malloc(sizeof(struct node));
	flag->data=-1;
	flag->next=NULL;
    p=head;
 	while(p!=NULL)
	{    	
          i++;
          if(i==pos) flag=p;
          p=p->next;
    }
	return flag;
}
     
int main()
{
  struct node	*head;
   int	pos,choice,data;
	head=(struct node*) malloc(sizeof(struct node));
	head=NULL;
	do
	{
	  printf("\n1.Create\n2.Insert\n3.Delete\n4.Locate\n5.Retrieve\n6.Display\n7.Make empty\n8.Exit");
	  printf("\n Enter choice : ");
	  scanf("%d",&choice);
	  switch(choice)
	  {
                    case 1: head=create(head);break;
                    case 2:
                           {
                              printf("\n1.Beginning\n2.End\n3.Middle\nEnter choice :");
                              scanf("%d",&choice);
                              switch(choice)
                              {
                                            case 1: head=insert(head,1);break;
                                            case 2: head=insert(head,0);break;
                                            case 3: printf("\nEnter the position to be inserted : ");
                                                 	scanf("%d",&pos);
                                                    head=insert(head,pos);
                                                    break;
                              }
                           }break;
                    case 3: 
                           {
                              printf("\nEnter the position to be deleted : ");
                              scanf("%d",&pos);
                              head=del(head,pos); 
                           }break;             
                    case 4:
                           {
                              printf("\nEnter the data to be located : ");
                              scanf("%d",&data);
                              pos=locate(head,data);
                              if(pos==0)printf("\nData not found\n");
                              else printf("\nData found at position %d\n",pos);
                           }break;
                    case 5:
                           {
                              struct node *temp;
                              temp=(struct node*) malloc(sizeof(struct node));
                              printf("\nEnter the position to be retrieved : ");
                              scanf("%d",&pos);
                              temp=retrieve(head,pos);
                              if(temp->data==-1)printf("\nData not found\n");
                              else printf("\nData found at position %d is %d\n",pos,temp->data);
                           }break;
                    case 6: display(head);break;
                    case 7: head=make_empty(head);break;
                    case 8: return 0;
      }
   }while(5);
   getch();
} 
