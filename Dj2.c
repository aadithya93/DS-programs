//Djikstra algorithm

#include<stdio.h>
#include<conio.h>
#define MAX 10
struct table
{
       int known[MAX];
       int dist[MAX];
       int pv[MAX];
       
}T;
struct graph
{
       int matrix[MAX][MAX];
       int n;
}G;
void readgraph()
{
     int i,j,u,v,cost,ch=1;
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
         printf("enter the cost ");
         scanf("%d",&cost);
         G.matrix[u-1][v-1]=cost;
         printf("\ndo you want to enter another edge (1-yes 2-no)");
         scanf("%d",&ch);
     }
}
void displaymat()
{
     int i,j;
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
void inittable()
{
     int i;
     for(i=0;i<G.n;i++)
     {
             T.known[i]=0;
             T.dist[i]=999;
             T.pv[i]=0;
     }
}            
int smallest()
{
    int i,min=999,index=-1;
    for(i=0;i<G.n;i++)
    {
                     if(T.known[i]==0 && T.dist[i]<min)
                     {
                            min=T.dist[i];
                            index=i;
                     }                
    } 
    return index;
}    
void displaytable()
{
    int i;
    printf("\nVertex Known distance previous\n");
    for(i=0;i<G.n;i++)
    { 
         printf("\n\nV %d \t %d \t %d \t %d",i+1,T.known[i], T.dist[i], T.pv[i]);
    }
}
     

void dj(int start)
{
      int i,j,small=start-1;
           T.dist[start-1]=0;
      for(;;)
      {      
             printf("hi");
             T.known[small]=1;
             displaytable();
             for(j=0;j<G.n;j++)
             {
                               if(T.known[j]==0 && G.matrix[small][j]!=0)
                                    if(T.dist[small] + G.matrix[small][j] < T.dist[j])
                                    {
                                                     T.pv[j]=small+1;
                                                     T.dist[j]=T.dist[small] + G.matrix[small][j];
                                    }
             }
             small=smallest();
             if(small==-1)
                 break;                       
      }
}               
int main()
{
       int start;
       printf("\nDIJKSTRA ALGORITHM");
       readgraph();
       displaymat();
       inittable();
       printf("\nEnter the starting Vertex:");
       scanf("%d",&start);
       dj(start);
       printf("\nfinal:");
       displaytable();
       getch();
       return 0;
}
