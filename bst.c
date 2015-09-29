// Binary Search Tree

#include<stdio.h>
#include<malloc.h>

struct bst
{
       int data;
       struct bst *left,*right;
};

struct bst* insert(struct bst *T,struct bst *temp)
{
       if(T==NULL) T=temp;
       if(temp->data<T->data)T->left=insert(T->left,temp);
       if(temp->data>T->data)T->right=insert(T->right,temp);
       return T;
}

struct bst* find_min(struct bst *T)
{
       if(T==NULL)return T;
       else
       {
           if(T->left!=NULL)return find_min(T->left);
           else return T;
       }
}

struct bst* find_max(struct bst *T)
{
       if(T==NULL)return T;
       else
       {
           if(T->right!=NULL)return find_max(T->right);
           else return T;
       }
}

struct bst* find(struct bst *T,int data)
{
       if(T==NULL)return T;
       else
       {
           if(T->data==data) return T;
           else if(data<T->data) return find(T->left,data);
           else if(data>T->data) return find(T->right,data);
       }
}

void inorder(struct bst *T)
{
     if(T==NULL) printf("\nEmpty tree");
     else
     {
         if(T->left!=NULL)inorder(T->left);
         printf("%d\t",T->data);
         if(T->right!=NULL)inorder(T->right);
     }
}
 
void preorder(struct bst *T)
{
     if(T==NULL) printf("\nEmpty tree");
     else
     {
         printf("%d\t",T->data);
         if(T->left!=NULL)preorder(T->left);
         if(T->right!=NULL)preorder(T->right);
     }
}

void postorder(struct bst *T)
{
     if(T==NULL) printf("\nEmpty tree");
     else
     {
         if(T->left!=NULL)postorder(T->left);
         if(T->right!=NULL)postorder(T->right);
         printf("%d\t",T->data);         
     }
} 

struct bst* del(struct bst *T,int data)
{
       if(T==NULL) return T;
       else
       {
           if(data<T->data) T->left=del(T->left,data);
           if(data>T->data) T->right=del(T->right,data);
           if(data==T->data)
           {
                   if(T->left && T->right)
                   {
                         struct bst *tmpcell;
                         tmpcell=find_min(T->right);
                         T->data=tmpcell->data;
                         T->right=del(T->right,tmpcell->data);
                   }
                   else
                   {
                       struct bst *tmpcell;
                       tmpcell=T;
                       if(T->left==NULL) T=T->right;
                       else if(T->right==NULL) T=T->left;
                       free(tmpcell);
                   }
           }
           return T;
       }
}
        
int main()
{
    struct bst *T;
    T=NULL;
    int ch;
    do
    {
       printf("\n\n   \t\t\tBINARY SEARCH TREE\n"); 
       printf("\n1.Insert\n2.Delete\n3.Display\n4.Find min\n5.Find max\n6.Find\n7.Exit\nEnter your choice : ");
       scanf("%d",&ch);
       switch(ch)
       {
              case 1:
                   {
                        struct bst *temp;
                        temp=(struct bst*)malloc(sizeof(struct bst));
                        printf("\nEnter data to be inserted : ");
                        scanf("%d",&temp->data);
                        temp->left=NULL;
                        temp->right=NULL;
                        T=insert(T,temp);
                        break;
                   }
              case 2:
                   {
                        int data;
                        printf("\nEnter data to be deleted : ");
                        scanf("%d",&data);
                        T=del(T,data);
                        if(T==NULL)printf("\nEmpty tree");
                        break;
                   }
              case 3:
                   {
                        printf("\n1.Inorder traversal\n2.Preorder traversal\n3.Postorder traversal\nEnter choice : ");
                        scanf("%d",&ch);
                        switch(ch)
                        {
                                  case 1: inorder(T);
                                          break;
                                  case 2: preorder(T);
                                          break;
                                  case 3: postorder(T);
                                          break;
                                  default:break;
                        }          
                        break;
                   }
              case 4:
                   {
                        struct bst *min;
                        min=find_min(T);
                        if(min==NULL)printf("\nEmpty tree!!");
                        else printf("\nThe minimum value is %d",min->data);
                        break;
                   }
              case 5:
                   {
                        struct bst *max;
                        max=find_max(T);
                        if(max==NULL)printf("\nEmpty tree!!");
                        else printf("\nThe maximum value is %d",max->data);
                        break;
                   }
              case 6:
                   {
                        int data;
                        struct bst *fd;
                        printf("\nEnter data to be searched : ");
                        scanf("%d",&data);
                        fd=find(T,data);
                        if(fd==NULL) printf("\nData not found!!");
                        else printf("\n%d is found in the tree",fd->data);
                        break;
                   }
              case 7: return 0;
              default: printf("\n Wrong choice!!");
       }
    }while(5);
}
