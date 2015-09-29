#include<stdio.h>
#include<malloc.h>
#include<math.h>
struct list
{
       int element;
       struct list *next;
};

struct htable
{
       int tsize;
       struct list **tlist;
};

int hash(int key,int tsize,int i)
{
    int x;
        x=key/pow(tsize,i);
    return (x%tsize);
}
      
struct htable* initialize()
{
       struct htable *H;
       int i;
       
       H=malloc (sizeof(struct htable));
       H->tsize= 10;
       
       H->tlist=malloc (sizeof(struct list)*H->tsize);
       
       for(i=0;i<H->tsize;i++)
       {
           H->tlist[i]=malloc (sizeof(struct list));
           H->tlist[i]->next=NULL;
       }
       return H;
}

void makeempty(struct htable *H)
{
     int i;
     for(i=0;i<H->tsize;i++)
       {
           H->tlist[i]->next=NULL;
       }
}
     
void insert(int key,struct htable* H,int i)
{
     struct list *pos,*newcell,*l;
                  l=H->tlist[hash(key,H->tsize,i)];
                  pos=l;
                  while(pos!=NULL && pos->element!=key)
                  {
                     if(pos->next==NULL)
                     {                                  
                          newcell=malloc(sizeof(struct list));
                          newcell->next=NULL;
                          newcell->element =key;
                          pos->next=newcell;
                     }
                     pos=pos->next;
                  }
}

void sort(int a[],struct htable *H)
{
     int i,j=0;
     struct list *temp;
     for(i=0;i<H->tsize;i++)
     {
         temp=H->tlist[i]->next;
         while(temp!=NULL)
         {
               a[j]=temp->element;
               j++;
               temp=temp->next;
         }
     }
}

int digit(int n)
{
    int digit=0;
           while(n!=0)
           {
                      digit++;
                      n=n/10;
           }
           return digit;
}

void radix_sort(int a[],int n)
{
     struct htable *H;
     int i,j,max=0;
     H=initialize();
     for(i=0;i<n;i++)
           if(digit(a[i])>max)max=digit(a[i]);     
     for(i=0;i<max;i++)
     {
         for(j=0;j<n;j++)
             insert(a[j],H,i);
         sort(a,H);
         makeempty(H);
     }
     for(j=0;j<n;j++)
         printf("%d\n",a[j]);
}   

int main()
{
    int a[20],n,i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
           scanf("%d",&a[i]);
        radix_sort(a,n);
        system("pause");
        return 0;
}
