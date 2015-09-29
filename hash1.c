#include<stdio.h>
#include<malloc.h>

struct list
{
       int element;
       struct list *next;
};

struct hashtable
{
       int tablesize;
       struct list **thelists;
};

int hash(int key,int tablesize)
{
    return (key%tablesize);
}

int nextprime( int x)
{
    int i=x,c;
    while(c!=1)
    {
               int j;
               c=0;
               i++;
               for(j=2;j<=i;j++)
                  if(i%j==0)c++;
    }
    return i;
}        
struct hashtable* initialize(int tablesize)
{
       struct hashtable *H;
       int i;
       
       H=malloc (sizeof(struct hashtable));
       H->tablesize= nextprime(tablesize);
       
       H->thelists=malloc (sizeof(struct list)*H->tablesize);
       
       for(i=0;i<H->tablesize;i++)
       {
           H->thelists[i]=malloc (sizeof(struct list));
           H->thelists[i]->next=NULL;
       }
       return H;
}
struct list* find(int key, struct hashtable* H)
{
       struct list *p,*l;
       
       l=H->thelists[hash(key,H->tablesize)];
       p=l->next;
       while(p!=NULL && p->element!=key)
                     p=p->next;
       return p;
}

void insert(int key,struct hashtable* H)
{
     struct list *pos,*newcell,*l;
     
     pos=find(key,H);
     if(pos==NULL)
     {
                  newcell=malloc(sizeof(struct list));
                  
                  l=H->thelists[hash(key,H->tablesize)];
                  newcell->next=l->next;
                  newcell->element =key;
                  l->next=newcell;
     }
}

void display(struct hashtable *H)
{
     int i;
     struct list *temp;
     for(i=0;i<H->tablesize;i++)
     {
         temp=H->thelists[i]->next;
         while(temp!=NULL)
         {
               printf("%d\t",temp->element);
               temp=temp->next;
         }
         printf("\n");
     }
}

int main()
{
    int n,ch,data;
    struct hashtable *H;
    struct list *temp;
    printf("\nEnter the size of table : ");
    scanf("%d",&n);
    H=initialize(n);
    do
    {
              printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\nEnter choice : ");
              scanf("%d",&ch);
              switch(ch)
              {      
                     case 1:
                          printf("\nEnter data to be inserted : ");
                          scanf("%d",&data);
                          insert(data,H);
                          break;
                     case 2:
                          printf("\nEnter data to be searched : ");
                          scanf("%d",&data);
                          temp=find(data,H);
                          if(temp==NULL)printf("\nData not found");
                          else printf("%d is found",temp->element);
                          break;
                     case 3:
                          display(H);
                          break;
                     case 4:
                          return 0;
              }
    }while(5);
}             
