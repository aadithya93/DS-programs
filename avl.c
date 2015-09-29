#include<stdio.h>
#include<malloc.h>

struct avl
{
	int data;
	struct avl *left,*right;
	int height;
};
int height(struct avl *p)
{
        if(p==NULL)
	    	return -1;
	else
		return p->height;
}

int max(int x,int y)
{
	if(x>y)return x;
	else return y;
}

struct avl* singlerotatewithleft(struct avl* k2)
{
	struct avl* k1;
	k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	k2->height=max(height(k2->left),height(k2->right))+1;	
	k1->height=max(height(k1->left),k2->height)+1;
	return k1;
}

struct avl* singlerotatewithright(struct avl* k2)
{
	struct avl* k1;
	k1=k2->right;
	k2->right=k1->left;
	k1->left=k2;
	k2->height=max(height(k2->left),height(k2->right))+1;	
	k1->height=max(height(k1->right),k2->height)+1;
	return k1;
}

struct avl* doublerotatewithleft(struct avl *k3)
{
	k3->left=singlerotatewithright(k3->left);
	return singlerotatewithleft(k3);
}

struct avl* doublerotatewithright(struct avl *k3)
{
	k3->right=singlerotatewithleft(k3->right);
	return singlerotatewithright(k3);
}

struct avl* insert(struct avl *t,int x)
{
	if(t==NULL)
	{
		t=(struct avl*) malloc(sizeof(struct avl));
		t->data=x;
		t->height=0;
		t->left=t->right=NULL;
	}
	else if(x<t->data)
	{
		t->left=insert(t->left,x);
		if(height(t->left)- height(t->right)==2)
		{
			if(x<t->left->data)
				t=singlerotatewithleft(t);
			else
				t=doublerotatewithleft(t);
		}
	}
	
	else if(x>t->data)
	{
		t->right=insert(t->right,x);
		if(height(t->right)- height(t->left)==2)
		{
			if(x>t->right->data)
				t=singlerotatewithright(t);
			else
				t=doublerotatewithright(t);
		}
	}
	t->height=max(height(t->left),height(t->right))+1;
	return t;
}

struct avl* find_min(struct avl *t)
{
       if(t==NULL)return t;
       else
       {
           if(t->left!=NULL)return find_min(t->left);
           else return t;
       }
}

struct avl* find_max(struct avl *t)
{
       if(t==NULL)return t;
       else
       {
           if(t->right!=NULL)return find_max(t->right);
           else return t;
       }
}

struct avl* find(struct avl *t,int data)
{
       if(t==NULL)return t;
       else
       {
           if(t->data==data) return t;
           else if(data<t->data) return find(t->left,data);
           else if(data>t->data) return find(t->right,data);
       }
}

struct avl* del(struct avl *t,int x)
{
    if(t==NULL)
	           return t;
	else if(x<t->data)
	{
        t->left=del(t->left,x);
		if(height(t->left)- height(t->right)==2)
		{
			if(x<t->data)
				t=singlerotatewithright(t);
		}
	}
	
	else if(x>t->data)
	{
		t->right=del(t->right,x);
		if(height(t->right)- height(t->left)==2)
		{
			if(x>t->data)
				t=singlerotatewithleft(t);
		}
	}
	if(x==t->data)
           {
                   if(t->left && t->right)
                   {
                         struct avl *tmpcell;
                         tmpcell=find_min(t->right);
                         t->data=tmpcell->data;
                         t->right=del(t->right,tmpcell->data);
                   }
                   else
                   {
                       struct avl *tmpcell;
                       tmpcell=t;
                       if(t->left==NULL) t=t->right;
                       else if(t->right==NULL) t=t->left;
                       free(tmpcell);
                   }
           }
	if(t!=NULL)t->height=max(height(t->left),height(t->right))+1;
	return t;
}

void inorder(struct avl *t)
{
     if(t==NULL) printf("\nEmpty tree");
     else
     {
         if(t->left!=NULL)inorder(t->left);
         printf("%d\t",t->data);
         if(t->right!=NULL)inorder(t->right);
     }
}

void preorder(struct avl *t)
{
     if(t==NULL) printf("\nEmpty tree");
     else
     {
         printf("%d\t",t->data);
         if(t->left!=NULL)preorder(t->left);
         if(t->right!=NULL)preorder(t->right);
     }
}

void postorder(struct avl *t)
{
     if(t==NULL) printf("\nEmpty tree");
     else
     {
         if(t->left!=NULL)postorder(t->left);
         if(t->right!=NULL)postorder(t->right);
         printf("%d\t",t->data);         
     }
}

struct avl* makeempty(struct avl *t)
{
       if(t!=NULL)
       {
                  t->left=NULL;
                  t->right=NULL;
       }
       return NULL;
}

int main()
{
    struct avl *t;
    t=NULL;
    int ch;
    do
    {
       printf("\n1.Insert\n2.Delete\n3.Display\n4.Find min\n5.Find max\n6.Find\n7.Make empty\n8.Exit\nEnter your choice : ");
       scanf("%d",&ch);
       switch(ch)
       {
              case 1:
                   {
                        int x;
                        printf("\nEnter data to be inserted : ");
                        scanf("%d",&x);
                        t=insert(t,x);
                        break;
                   }
              case 2:
                   {
                        int data;
                        printf("\nEnter data to be deleted : ");
                        scanf("%d",&data);
                        t=del(t,data);
                        if(t==NULL)printf("\nEmpty tree");
                        break;
                   }
              case 3:
                   {
                        printf("\n1.Inorder traversal\n2.Preorder traversal\n3.Postorder traversal\nEnter choice : ");
                        scanf("%d",&ch);
                        switch(ch)
                        {
                                  case 1: inorder(t);
                                          break;
                                  case 2: preorder(t);
                                          break;
                                  case 3: postorder(t);
                                          break;
                                  default:break;
                        }          
                        break;
                   }
              case 4:
                   {
                        struct avl *min;
                        min=find_min(t);
                        if(min==NULL)printf("\nEmpty tree!!");
                        else printf("\nthe minimum value is %d",min->data);
                        break;
                   }
              case 5:
                   {
                        struct avl *max;
                        max=find_max(t);
                        if(max==NULL)printf("\nEmpty tree!!");
                        else printf("\nthe maximum value is %d",max->data);
                        break;
                   }
              case 6:
                   {
                        int data;
                        struct avl *fd;
                        printf("\nEnter data to be searched : ");
                        scanf("%d",&data);
                        fd=find(t,data);
                        if(fd==NULL) printf("\nData not found!!");
                        else printf("\n%d is found in the tree",fd->data);
                        break;
                   }
              case 7:
                   {
                        t=makeempty(t);
                        break;
                   }
              case 8: return 0;
              default: printf("\n Wrong choice!!");
       }
    }while(5);
}

