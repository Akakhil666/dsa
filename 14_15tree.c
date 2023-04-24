#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node * left ,*right;
};

typedef struct node * nodeptr;

nodeptr insert(nodeptr, int);
void in(nodeptr );
void pre(nodeptr );
void post(nodeptr );
int max(nodeptr );
int min(nodeptr );
int count(nodeptr );

int main()
{
    int ch,ele;
    nodeptr p;
    p='\0';

    read:

    printf("\n1--to enter a ele\n2--preorder\n3--inorder\n4--postorder\n5--maximum\n6--minimum\n7--to coutn num of nodes\n8--exit\n\n");
    printf("\nenter the choice");
    scanf("%d",&ch);

    switch (ch)
    {
        case 1:printf("enter the ele to be inserted ");
               scanf("%d",&ele);
               p=insert(p,ele);
               break;

        case 2:pre(p);
               break;

        case 3:in(p);
               break;

        case 4:post(p);
               break;

        case 5:ele=min(p);
               if(ele!=-1)
               printf("the min ele is %d",ele);
               break;

        case 6:ele=max(p);
               if(ele!=-1)
               printf("the max ele is %d",ele);
               break;

        case 7:ele=count(p);
               if(ele!=-1)
               printf("the the number of nodes  is %d",ele);
               break;

        case 8:return 0;
    }
    goto read;
}

nodeptr insert(nodeptr p,int ele)
{
    nodeptr q,cur,prev;
    q=(nodeptr)malloc(sizeof(struct node));
    q->info=ele;
    q->right='\0';
    q->left='\0';

    if(p=='\0')
    {
        return q;
    }
    else
    {
        cur=p;
        prev='\0';
        while(cur!='\0')
        {
            prev=cur;
            if(ele==cur->info)
            {
                printf("duplicate ele");
                return p;
            }
            else if(ele<cur->info)
            {
                cur=cur->left;
            }
            else
            {
                cur=cur->right;
            }
        }
        if(ele<prev->info)
        {
            prev->left=q;
        }
        else
        {
            prev->right=q;
        }
        return p;
    }

}

void in(nodeptr p)
{
    if(p=='\0')
    {
        return ;
    }
    else
    {
        in(p->left);
        printf("%d",p->info);
        in(p->right);
    }
}

void pre(nodeptr p)
{
    if(p=='\0')
    {
        return ;
    }
    else
    {
        printf("%d",p->info);
        pre(p->left);
        pre(p->right);
    }
}

void post(nodeptr p)
{
    if(p=='\0')
    {
        return ;
    }
    else
    {
        post(p->left);
        post(p->right);
        printf("%d",p->info);

    }
}

int min(nodeptr p)
{
    nodeptr cur;
    if(p=='\0')
    {
        printf("the tree is empty");
        return -1;
    }
    else
    {
        cur=p;
        while(cur->left!='\0')
        {
            cur=cur->left;
        }
        return cur->info;
    }
}

int max(nodeptr p)
{
    nodeptr cur;
    if(p=='\0')
    {
        printf("the tree is empty");
        return -1;
    }
    else
    {
        cur=p;
        while(cur->right!='\0')
        {
            cur=cur->right;
        }
        return cur->info;
    }
}

int count(nodeptr p)
{
    if(p=='\0')
    {
        return 0;
    }
    return 1+count(p->left)+count(p->right);
}