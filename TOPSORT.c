//topologiical sort

#include<stdio.h>
#include<conio.h>
#define MAX 10
struct queue     
{
   int rear,front;
   int data[MAX];
   int capacity;
}q;
struct graph
{
       int matrix[MAX][MAX];
       int n;
}G;
void readgraph()
{
     int i,j,u,v,ch=1;
     printf("\nEnter no. of vertices:");
     scanf("%d",&G.n);
     for(i=0;i<G.n;i++)
        for(j=0;j<G.n;j++)
            G.matrix[i][j]=0;     
     while(ch==1)
     {
         printf("enter the first vertex ");
         scanf("%d",&u);
         printf("enter the next vertex ");
         scanf("%d",&v);
         G.matrix[u-1][v-1]=1;
         printf("\ndo you want to enter another edge (1-yes 2-no)");
         scanf("%d",&ch);
     }
}
void displaymat()
{         
     int i,j; 
        printf("\nAdjacency matrix\n\n");
      for(i=0;i<G.n;i++)
           printf("\tV %d",i+1);
      printf("\n\n");
      for( i=0;i<G.n;i++)
      {
                printf("V %d",i+1);
                printf("\t");
                for(j=0;j<G.n;j++)
                {
                     printf("%d",G.matrix[i][j]);
                     printf("\t");
                }
                printf("\n");
      }
}
int indegree[MAX];
void indegcal()
{
     int i,j;
  for(i=0; i<G.n;i++)
    for(j=0;j<G.n;j++)
    {
                      if(G.matrix[j][i])
                           indegree[i]++;
    }
}
void enqueue(int x)
{
   if(q.front==-1)
           q.front=q.rear=0;
   else
           ++q.rear;
   q.data[q.rear]=x;
}
int isempty()
{
    if(q.rear==q.front-1)
      return 1;
    return 0;
}
int dequeue()
{ 
     if(isempty(q)==0) 
         return q.data[q.front++];
}
void topsort()
{
     int i,temp;   
     for(i=0;i<G.n;i++)
        if(indegree[i]==0)
          enqueue(i+1);
     while(isempty(q)==0)
     { 
          temp=dequeue();
          printf("%d ", temp);
          temp--;
          for(i=0;i<G.n;i++)
             if(G.matrix[temp][i])
                if(--indegree[i]==0)
                   enqueue(i+1);
     }
}
int main()
{
    int i;
    q.rear=q.front=-1;
    readgraph();
    displaymat();
    indegcal();
    printf("\nTOPOLOGICAL SORT");
    topsort();
    getch();
    return 0;
}
