#include<stdio.h>
#include<malloc.h>

struct hashentry
{
       int element;
       int info;
};

struct htable
{
       int tsize;
       int no;
       struct hashentry *tcell;
};

int hash(int key,int tsize)
{
    return (key%tsize);
}

int nextprime( int x)
{
    int i=x,c;
    while(c!=1)
    {
               int j;
               c=0;
               for(j=2;j<=i;j++)
                  if(i%j==0)c++;
               i++;
    }
    return (i-1);
}        

struct htable* initialize(int tsize)
{
       struct htable *H;
       int i;
       
       H=malloc (sizeof(struct htable));
       H->tsize= nextprime(tsize);
       H->no=0;
       
       H->tcell=malloc (sizeof(struct hashentry)*H->tsize);
       
       for(i=0;i<H->tsize;i++)
       {
              H->tcell[i].info=0;
       }
       return H;
}

int find(int key, struct htable* H)
{
       int pos;
       int num;
       num=key;
       
       pos=hash(key,H->tsize);
       while(H->tcell[pos].info!=0 && H->tcell[pos].element!=key)
       {
               pos=hash(++num,H->tsize);
               if(pos>=H->tsize) pos-=H->tsize;
       }
       
       return pos;
}

struct htable* insert(int,struct htable*);

struct htable* rehash(int tsize,struct htable * H)
{
       int n,i=0;
       struct htable *H1;
       H1=initialize(tsize);
       for(i=0;i<H->tsize;i++)
       {
          if(H->tcell[i].info!=0)
          {    
              n=H->tcell[i].element;
              H1=insert(n,H1);
          }
       }
       return H1;
}

struct htable* insert(int key,struct htable* H)
{
     int pos;
     
     pos=find(key,H);       
     if(H->tcell[pos].info!=1)
     {
            H->tcell[pos].info=1;
            H->tcell[pos].element=key;
            H->no++;
     }
     if((H->no/(float)H->tsize)*100>=70)
            H=rehash(H->tsize*2,H);
     return H;
}

void del(int key, struct htable* H)
{
       int i=0,l,s,index,empty;
       index=hash(key,H->tsize);
       s=H->tsize;
       while(H->tcell[(index+i)%s].info==1)
       {
              l=(index+i)%s;
              if(H->tcell[l].element==key)
              {
                     H->tcell[l].element=1;
                     H->tcell[l].info=0;
                     printf("\nItem has been deleted!");
                     i++;
                     H->no--;
                     empty=l;
                     break;
              }
              i++;
       }
       while(H->tcell[(index+i)%s].info!=0)
       {
              if(hash(H->tcell[(index+i)%s].element,s)==index)
              {
                     H->tcell[empty%s].element=H->tcell[(index+i)%s].element;
                     H->tcell[(index+i)%s].info=0;
                     H->tcell[empty%s].info=1;
                     empty=(index+i)%s;
              }
              i++;
       }
}

void display(struct htable *H)
{
     int i;
     for(i=0;i<H->tsize;i++)
     {
         printf("\n%d    :",i);                   
         if(H->tcell[i].info!=0)
             printf("%d",H->tcell[i].element);
        printf("\n\n");
     }
}

int main()
{
    int n,ch,data;
    struct htable *H;
    int temp;
    printf("\nEnter the size of table : ");
    scanf("%d",&n);
    H=initialize(n);
    do
    {
              printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter choice : ");
              scanf("%d",&ch);
              switch(ch)
              {      
                     case 1:
                          printf("\nEnter data to be inserted : ");
                          scanf("%d",&data);
                          H=insert(data,H);
                          break;
                     case 2:
                          printf("\nEnter data to be deleted : ");
                          scanf("%d",&data);
                          del(data,H);
                          break;
                     case 3:
                          printf("\nEnter data to be searched : ");
                          scanf("%d",&data);
                          temp=find(data,H);
                          if(H->tcell[temp].info==1)
                              printf("%d is found in key position %d",H->tcell[temp].element,temp);
                          else
                              printf("\nData not found!");
                          break;
                     case 4:
                          display(H);
                          break;
                     case 5:
                          return 0;
              }
    }while(5);
}             
