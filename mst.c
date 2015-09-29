#include<stdio.h>
#include<malloc.h>
#define MAX 20

struct node
{
       int v,known,dv,pv;
};

struct heaps
{
       int Capacity;
       int Size;
       struct node *Elements;
};

struct heaps* Initialize( int MaxElements )
{
  struct heaps* H;
                H = malloc( sizeof( struct heaps ) );
  H->Elements = (struct node*) malloc( ( MaxElements + 1 )* sizeof( struct node ) );
  H->Capacity = MaxElements;
  H->Size = 0;
  H->Elements[ 0 ].known = -1;
  H->Elements[ 0 ].pv = -1;
  H->Elements[ 0 ].dv = -1;
  H->Elements[ 0 ].v = -1;
  return H;
}

int IsEmpty( struct heaps *H )
{
   return H->Size == 0;
}

int IsFull( struct heaps *H )
{
        return H->Size == H->Capacity;
}
void Insert( struct node X, struct heaps *H )
{
     int i;
     if( IsFull( H ) )
     {
        printf( "\nPriority queue is full" );
        return;
     }
     for( i = ++H->Size; H->Elements[ i / 2 ].dv > X.dv; i /= 2 )
     H->Elements[ i ] = H->Elements[ i / 2 ];
     H->Elements[ i ] = X;
}
void makeempty(struct heaps *H)
{
     H->Size=0;
}

/*struct node DeleteMin( struct heaps *H )
{
    int i, Child;
    struct node MinElement;
    struct node  LastElement;
    if( IsEmpty( H ) )
    {
       printf( "\nPriority queue is empty" );
       return H->Elements[ 0 ];
    }
    MinElement = H->Elements[ 1 ];
    LastElement = H->Elements[ H->Size-- ];
    for( i = 1; i * 2 <= H->Size; i = Child )
    {
         Child = i * 2;
         if( Child != H->Size && H->Elements[ Child + 1 ]< H->Elements[ Child ] )
              Child++;
         if( LastElement > H->Elements[ Child ] )
             H->Elements[ i ] = H->Elements[ Child ];
         else
             break;
    }
    H->Elements[ i ] = LastElement;
    return MinElement;
}*/
struct tree
{
       int s,d;
};

int inputgraph(int a[MAX][MAX],int n)
{
     int i,j,ch,w,count=0;
     for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
               a[i][j]=0;
     do
     {
              do
              {
                printf("\nEnter the nodes that are connected : ");
                scanf("%d%d",&i,&j);
              }while(i==j || i>n || j>n);
              printf("\nEnter the weight of the node : ");
              scanf("%d",&w);         
              a[i][j]=w;
              a[j][i]=w;
              count++;
              printf("\nDo u want to continue (1.Yes 2.No) : ");
              scanf("%d",&ch);
     }while(ch==1);
     for(i=1;i<=n;i++)
     {
        for(j=1;j<=n;j++)
               printf("%d\t",a[i][j]);
        printf("\n");
     }
     return count;
}

int check(struct node no[],int n)
{
    int i;
    for(i=1;i<=n;i++)
            if(no[i].known==0) return 0;
    return 1;
}
void mst(int a[MAX][MAX],int n)
{
     struct node table[n+1];
     struct tree mst[n];
     int i,k,cur,inp,t=0;
     struct heaps *H;
     H=Initialize(n);
     for(i=1;i<=n;i++)
     {
          table[i].v=i;
          table[i].known=0;
          table[i].dv=999;
          table[i].pv=0;
     }
     printf("\nEnter the starting point : ");
     scanf("%d",&inp);
     i=inp;
     table[i].known=1;
     table[i].dv=0;
     table[i].pv=0;
     cur=i;
     while(check(table,n)==0)
     {
          for(k=1;k<=n;k++)
          {
                           if(a[cur][k]>0 && table[k].known==0)
                           {
                               if(a[cur][k]<table[k].dv)
                               {
                                    table[k].pv=cur;
                                    table[k].dv=a[cur][k];
                               }
                           }
          }
          for(k=1;k<=n;k++)
          {
                 if(table[k].known==0)
                           Insert(table[k],H);
          }
          cur=H->Elements[1].v;
          table[cur].known=1;
          t++;
          mst[t].s=table[cur].pv;
          mst[t].d=cur;
          makeempty(H);
          printf("\nVertex    Known    Dv       Pv\n");
          for(k=1;k<=n;k++)
          {
                 printf("   %d\t    %d \t   %d  \t    %d\n",table[k].v,table[k].known,table[k].dv,table[k].pv);
          }        
     }
     for(k=1;k<n;k++)
     {
           printf("\nvertex(%d) to vertex(%d)",mst[k].s,mst[k].d);
           printf(" of weight %d",a[mst[k].s][mst[k].d]);
     }
     printf("\n");
}

int main()
{
    int n,a[MAX][MAX],c;
        printf("\nEnter number of nodes : ");
        scanf("%d",&n);
        c=inputgraph(a,n);
        if(c<n-1)printf("\nMST not possible\n");
        else mst(a,n);
        system("pause");
        return 0;
}
