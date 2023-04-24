#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *left,*right;
};

typedef struct node * nodeptr;

nodeptr insert_front(nodeptr ,int);
nodeptr insert_rear(nodeptr ,int);
nodeptr insert_after(nodeptr ,int ,int);
nodeptr insert_before(nodeptr ,int ,int);
nodeptr delete_front(nodeptr );
nodeptr delete_rear(nodeptr );
void display(nodeptr);


int main()
{
    nodeptr p;
    int ch,ele,key;

    p='\0';

    read:

    printf("\n1--to insert at front\n2--to insert at rear\n3--to insert after key\n4--to insert before key\n5--to delete at front\n6--to delete at rear\n7--to display\n8--to exit\n");
    printf("enter your choice");
    scanf("%d",&ch);

    switch (ch)
    {
        case 1:printf("enter the ele to be inserted ");
               scanf("%d",&ele);
               p=insert_front(p,ele);
               break;

        case 2:printf("enter the ele to be inserted ");
               scanf("%d",&ele);
               p=insert_rear(p,ele);
               break;

        case 3:printf("enter the ele to be inserted ");
               scanf("%d",&ele);
               printf("enter the key afer the ele to be inserted");
               scanf("%d",&key);
               p=insert_after(p,key,ele);
               break;

        case 4:printf("enter the ele to be inserted ");
               scanf("%d",&ele);
               printf("enter the key before the ele to be inserted");
               scanf("%d",&key);
               p=insert_before(p,key,ele);
               break;

      case 5:p=delete_front(p);
             break;

      case 6:p=delete_rear(p);
             break;

        case 7:display(p);
               break;

        case 8:return 0;
    }
    goto read;
}


nodeptr insert_front(nodeptr p,int ele)
{
    nodeptr q;
    q=(nodeptr)malloc(sizeof(struct node));
    q->info=ele;
    q->left='\0';
    q->right='\0';

    if(p=='\0')
    {
        return q;
    }
    else
    {
        q->right=p;
        p->left=q;
        p=q;
        return p;
    }
}

nodeptr insert_rear(nodeptr p,int ele)
{
    nodeptr q,cur;
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

        while(cur->right!='\0')
        {
            cur=cur->right;
        }

        cur->right=q;
        q->left=cur;
        return p;
    }
}

nodeptr delete_front(nodeptr p)
{
    nodeptr q;
    if(p=='\0')
    {
        printf("the ll is empty");
        return '\0';
    }
    else if(p->right=='\0')
    {
        printf("the deleted ele is %d",p->info);
        free(p);
        return '\0';
    }
    else
    {
        q=p;
        p=p->right;
        printf("the delted ele is %d",q->info);
        free(q);
        p->left='\0';
        return p;
    }
}

nodeptr delete_rear(nodeptr p)
{
    nodeptr cur,prev;
    if(p=='\0')
    {
        printf("the ll is empty");
        return '\0';
    }
    else if(p->right=='\0')
    {
        printf("the dleted ele is %d",p->info);
        free(p);
        return '\0';
    }
    else
    {
        cur=p;
        prev='\0';
        while(cur->right!='\0')
        {
            prev=cur;
            cur=cur->right;
        }
        printf("the deleted ele is %d",cur->info);
        free(cur);
        prev->right='\0';
        return p;
    }
}

nodeptr insert_after(nodeptr p,int key,int ele)
{
    nodeptr q,cur,after;
    q=(nodeptr)malloc(sizeof(struct node));
    q->info=ele;
    q->left='\0';
    q->right='\0';

    if(p=='\0')
    {
        printf("the ll is empty");
        return '\0';
    }
    else 
    {
        cur=p;

        while(cur->right!='\0')
        {
            if(cur->info==key)
            {
                after=cur->right;
                cur->right=q;
                q->left=cur;
                after->left=q;
                q->right=after;
                return p;
            }
            else
            cur=cur->right;
        }

        if(cur->info==key)
        {
            cur->right=q;
            q->left=cur;
            return p;
        }
        else{
            printf("hte key is not found");
            return '\0';
        }
    }
}

nodeptr insert_before(nodeptr p,int key,int ele)
{
    nodeptr q,cur,prev;
    q=(nodeptr)malloc(sizeof(struct node));
    q->info=ele;
    q->right='\0';
    q->left='\0';

    if(p=='\0')
    {
        printf("the ll is empty");
        return '\0';
    }
    else if(p->info==key)
    {
        q->right=p;
        p->left=q;
         p=q;
        return p;
    }
    else
    {
        cur=p;
        prev='\0';

        while(cur!='\0')
        {
            if(cur->info==key)
            {
                prev->right=q;
                q->left=prev;
                cur->left=q;
                q->right=cur;
                return p;

            }
            else
            {
                prev=cur;
                cur=cur->right;
            }
        }

        printf("key is not fond");
        return p;
    }
}

void display(nodeptr p)
{
    nodeptr cur;
    if(p=='\0')
    {
        printf("the ll is empty");
        return ;
    }
    else
    {
        cur=p;
        while(cur!='\0')
        {
            printf("%d",cur->info);
            cur=cur->right;
        }
    }
}