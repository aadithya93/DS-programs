#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<math.h>

struct node
{
	int	coeff,power;
        struct node    *next;
};

struct node* create(struct node *head)
{
   struct node *p,*c;
	p=(struct node*) malloc(sizeof(struct node));
   int	ch=0;
	do
	{
		c=(struct node*) malloc(sizeof(struct node));
		printf("\nEnter the co efficient : ");
		scanf("%d",&c->coeff);
		printf("\nEnter the exponent : ");
		scanf("%d",&c->power);
		c->next=NULL;
		if(head==NULL)
			head=c;
		else
			p->next=c;
		p=c;
		printf("\nDo tou want to add more terms? (Yes-1 or No-0) : ");
		scanf("%d",&ch);	
	}while(ch==1);
	return head;
}

void display(struct node *head)
{
  struct node	*p;
	p=(struct node*) malloc(sizeof(struct node));
	p=head;
 	while(p!=NULL)
	{
		if(p!=NULL)
		{
			if(p->coeff<0)
				printf("-");
			else printf("+");
		}
        if((p->power==0)||(p->power==-1)) printf(" %d ",abs(p->coeff));
		else if(p->power==1)  printf(" %d x ",abs(p->coeff));
        else printf(" %d x^%d ",abs(p->coeff),p->power);
		p=p->next;
		
	}
	printf("\n");
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

void sort(struct node *head,int x)
{
     int a[x],b[x],i=0,j;
     struct node *p;
	 p=(struct node*) malloc(sizeof(struct node));
	 p=head;
     while(p!=NULL)
     {
             a[i]=p->coeff;
	     b[i]=p->power;
             p=p->next;
             i++;
     }      
     for(i=0;i<x-1;i++)
     {
             for(j=0;j<x-i-1;j++)
             {
                   if (b[j] < b[j+1])
                   {
                    int temp;          
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
		    temp = b[j];
                    b[j] = b[j+1];
                    b[j+1] = temp;
                   }
             }
     }
     p=head;
     for(i=0;i<x;i++)
     {
             p->coeff=a[i];
	     p->power=b[i];
             p=p->next;
     } 
}  

struct node* add(struct node *p1,struct node*p2)
{
   struct node *p3,*c,*p;
	p3=(struct node*) malloc(sizeof(struct node));
	p=(struct node*) malloc(sizeof(struct node));
	p3=NULL;
	while((p1!=NULL)&&(p2!=NULL))
	{
		c=(struct node*) malloc(sizeof(struct node));
		c->next=NULL;
		if(p1->power>p2->power)
		{
			c->coeff=p1->coeff;
			c->power=p1->power;
			p1=p1->next;
		}
		else if(p2->power>p1->power)
		{
			c->coeff=p2->coeff;
			c->power=p2->power;
			p2=p2->next;
		}
		else if(p1->power==p2->power)
		{
			c->coeff=p1->coeff+p2->coeff;
			c->power=p1->power;
			p1=p1->next;
			p2=p2->next;
		}
		if(p3==NULL)
			p3=c;
		else
			p->next=c;
		p=c;	
	}
	while(p1!=NULL)
	{
		c=(struct node*) malloc(sizeof(struct node));
		c->next=NULL;
		c->coeff=p1->coeff;
		c->power=p1->power;
		p->next=c;
		p=c;
		p1=p1->next;
		
	}
	while(p2!=NULL)
	{
        c=(struct node*) malloc(sizeof(struct node));
		c->next=NULL;
		c->coeff=p2->coeff;
		c->power=p2->power;
		p->next=c;
		p=c;
        p2=p2->next;
	}	
	return p3;
}		

struct node* subtract(struct node *p1,struct node*p2)
{
   struct node *p3,*c,*p;
	p3=(struct node*) malloc(sizeof(struct node));
	p=(struct node*) malloc(sizeof(struct node));
	p3=NULL;
	while((p1!=NULL)&&(p2!=NULL))
	{
		c=(struct node*) malloc(sizeof(struct node));
		c->next=NULL;
		if(p1->power>p2->power)
		{
			c->coeff=p1->coeff;
			c->power=p1->power;
			p1=p1->next;
		}
		else if(p2->power>p1->power)
		{
			c->coeff=-1*p2->coeff;
			c->power=p2->power;
			p2=p2->next;
		}
		else if(p1->power==p2->power)
		{
			c->coeff=p1->coeff-p2->coeff;
			c->power=p1->power;
			p1=p1->next;
			p2=p2->next;
		}
		if(p3==NULL)
			p3=c;
		else
			p->next=c;
		p=c;	
	}
	while(p1!=NULL)
	{
		c=(struct node*) malloc(sizeof(struct node));
		c->next=NULL;
		c->coeff=p1->coeff;
		c->power=p1->power;
		p->next=c;
		p=c;
		p1=p1->next;
		
	}
	while(p2!=NULL)
	{
        c=(struct node*) malloc(sizeof(struct node));
		c->next=NULL;
		c->coeff=p2->coeff;
		c->power=p2->power;
		p->next=c;
		p=c;
        p2=p2->next;
	}	
	return p3;
}

struct node* multiply(struct node *p1,struct node *p2)
{
       int flag;
       struct node *p,*c,*p3,*t_p1,*t_p2;
       p3=(struct node*) malloc(sizeof(struct node));
	   p=(struct node*) malloc(sizeof(struct node));
       t_p1=(struct node*) malloc(sizeof(struct node));
       t_p2=(struct node*) malloc(sizeof(struct node));
	   p3=NULL;
	   t_p1=p1;
	   while(t_p1!=NULL)
	   {
            t_p2=p2;           
            while(t_p2!=NULL)
            {
                  p=p3;
                  flag=0;
                  while(p!=NULL)
                  {
                      if(t_p1->power+t_p2->power==p->power)
                      {
                           p->coeff+=t_p1->coeff*t_p2->coeff;
                           flag=1;
                           break;
                      }
                      p=p->next;
                  }
                  if(flag==0)
                  {
                          c=(struct node*) malloc(sizeof(struct node));
                          c->next=NULL;
                          c->coeff=t_p1->coeff*t_p2->coeff;
                          c->power=t_p1->power+t_p2->power;
                          if(p3==NULL) p3=c;
                          else 
                          {
                               p=p3;
                               while(p->next!=NULL)
                                      p=p->next;
                               p->next=c;
                          }
                  }
                  t_p2=t_p2->next;
            }
            t_p1=t_p1->next;
       }
       return p3;
}     
                          
struct node* differentiate(struct node *p1)
{
       struct node *p2,*c,*p;	
       p2=(struct node*) malloc(sizeof(struct node));
       p=(struct node*) malloc(sizeof(struct node));
       p2=NULL;
       p=NULL;
       while(p1!=NULL)
       {
            c=(struct node*) malloc(sizeof(struct node));
            c->next=NULL;
            c->coeff= p1->coeff * p1->power;
            c->power=p1->power-1;  
              
            if(p2==NULL)
			    p2=c;
		    else
		        if(c->power>=0)
                      p->next=c;
		     p=c;
		     p1=p1->next;
       }
       return p2;
}      	
int main()
{
    struct node	*p1,*p2,*p3,*p4,*p5,*p6;
    int	x,ch;
	do
	{
       printf("\n\t\t\t---------Polynomial----------\n");
       printf("\n\n\t1.Create\n\t2.Add\n\t3.Subtract\n\t4.Multiply\n\t5.Differentiate\n\t6.Exit");
	   printf("\nEnter choice : ");
	   scanf("%d",&ch);
       switch(ch)
	   {
              case 1:
                          p1=(struct node*) malloc(sizeof(struct node));
	                      p2=(struct node*) malloc(sizeof(struct node));
	                      p1=NULL;
	                      p2=NULL;
                      	  p1=create(p1);
                      	  x=count(p1);
                      	  sort(p1,x);
                      	  p2=create(p2);
                      	  x=count(p2);
                      	  sort(p2,x);
                      	  display(p1);
                      	  display(p2);
	                      break;
              case 2:
                          p3=add(p1,p2);
	                      display(p1);
                      	  display(p2);
                          printf("\nSum is : \n");
                          display(p3);
                          break;
              case 3:
             	          p3=subtract(p1,p2);
             	          display(p1);
                      	  display(p2);
                          printf("\nDifference is : \n");
                       	  display(p3);
                       	  break;
           	  case 4:
             	          p3=multiply(p1,p2);
             	          display(p1);
                      	  display(p2);
                          printf("\nProduct is : \n");
	                      display(p3);
	                      break;
              case 5:
                          p3=differentiate(p1);
                          display(p1);
                          printf("\nDifferential is : \n");
                          display(p3);
                          p3=differentiate(p2);
                          display(p2);
                          printf("\nDifferential is : \n");
                          display(p3);
                          break;
              case 6:
                          return 0;
       }
    }while(5);
}
