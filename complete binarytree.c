#include<stdio.h>
#include<malloc.h>
struct bt
{
       int data;
       struct bt *left,*right;
};
struct bt* create()                                 //TO CREATE TREE STRUCTURE
{
       struct bt *T;
              T=(struct bt*) malloc(sizeof(struct bt));
              T=NULL;
              return T;
}
int perfect(struct bt *T,int i)                        //TO CHECK IF A SUB TREE IS  A PERFECT BINARY TREE AND RETURN DEPTH
{
      int x,y;
      if(T==NULL) 
           return 0;
      else
      {
          if(T->left==NULL && T->right==NULL)
                 return i+1;     
          else if(T->left && T->right)
          {
             x=perfect(T->left,i+1);
             y=perfect(T->right,i+1);
             if(x == y) return x;
             return 0;
          }
          return 0;
      }
}           
struct bt* insert(struct bt *T,int x)                   //TO INSERT DATA IN COMPLETE BINARY TREE
{
       struct bt *temp;
              temp=(struct bt*) malloc(sizeof(struct bt));
              temp->data=x;
              temp->left=NULL;
              temp->right=NULL;
              if(T==NULL)
                   T=temp;
              else if(T->left==NULL)
                   T->left=temp;
              else if(T->right==NULL)
                   T->right=temp;
              else
              {
                   if(perfect(T->left,1)==perfect(T->right,1))
                       T->left=insert(T->left,x);
                   else if(perfect(T->left,1))
                       T->right=insert(T->right,x);
                   else
                       T->left=insert(T->left,x);
              }
              return T;
}
void postorder(struct bt *T)                       //TO DISPLAY IN POST ORDER
{
     if(T==NULL) printf("\nEmpty tree");
     else
     {
         if(T->left!=NULL)postorder(T->left);
         if(T->right!=NULL)postorder(T->right);
         printf("%d ",T->data);         
     }
} 
int main()
{
    struct bt *T;
    int x,ch;
        T=create();
        do
        {
                   printf("\n1.Insert\n2.Post order\n3.Exit\nEnter choice : ");
                   scanf("%d",&ch);
                   switch(ch)
                   {
                             case 1:
                                  printf("\nEnter data to be inserted : ");
                                  scanf("%d",&x);
                                  T=insert(T,x);
                                  break;
                             case 2:
                                  postorder(T);
                                  printf("\n");
                                  break;
                             case 3:
                                  return 0;
                   }
        }while(5);
}
