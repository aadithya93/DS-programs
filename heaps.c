//heaps

#include<stdio.h>
#include<malloc.h>
#define MAX 10
struct HeapStruct
{
int Capacity;
int Size;
int *Elements;
};

struct HeapStruct* Initialize( int MaxElements )
{
  struct HeapStruct* H;
                H = malloc( sizeof( struct HeapStruct ) );
  H->Elements = (int*) malloc( ( MaxElements + 1 )* sizeof( int ) );
  H->Capacity = MaxElements;
  H->Size = 0;
  H->Elements[ 0 ] = -1;
  return H;
}

int IsEmpty( struct HeapStruct *H )
{
   return H->Size == 0;
}

int IsFull( struct HeapStruct *H )
{
        return H->Size == H->Capacity;
}
void Insert( int X, struct HeapStruct *H )
{
     int i;
     if( IsFull( H ) )
     {
        printf( "\nPriority queue is full" );
        return;
     }
     for( i = ++H->Size; H->Elements[ i / 2 ] > X; i /= 2 )
     H->Elements[ i ] = H->Elements[ i / 2 ];
     H->Elements[ i ] = X;
}


int DeleteMin( struct HeapStruct *H )
{
    int i, Child;
    int MinElement, LastElement;
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
}

void heapsort( int a[],int n)
{
     int i;
     struct HeapStruct *H;
         H=Initialize(n);
         for(i=0;i<n;i++)
             Insert(a[i],H);
         i=0;
         while(!IsEmpty(H))
         {
                a[i]=DeleteMin(H);
                i++;
         }
}

int main()
{
    int a[MAX],n,i;
        printf("\nEnter number of elements : ");
        scanf("%d",&n);
        printf("\nEnter the elements to be sorted : \n");
        for(i=0;i<n;i++)
          scanf("%d",&a[i]);
        printf("\nThe list is : \n");
        for(i=0;i<n;i++)
          printf("%d\t",a[i]);
        heapsort(a,n);
        printf("\nThe sorted list is : \n");
        for(i=0;i<n;i++)
          printf("%d\t",a[i]);
        printf("\n");
        system("pause");
        return 0;
}
         

