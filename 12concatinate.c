#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node * next;
};

typedef struct node* nodeptr;

nodeptr insert(nodeptr ,int);
void display(nodeptr );
nodeptr con(nodeptr ,nodeptr );

int main()
{
    int ch,ele;
    nodeptr p1,p2;

    p1='\0';
    p2='\0';

    read:

    printf("\n1--to insert in p1\n2--to insert in p2\n3--to display pq\n4--to dispaly p2\n5--to concatinate two ll\n6--to exit\n");
    printf("enter your choice");
    scanf("%d",&ch);

    switch (ch)
    {
        case 1:printf("enter hte ele to be insertd");
               scanf("%d",&ele);
               p1=insert(p1,ele);
               break;
        
        case 2:printf("enter hte ele to be insertd");
               scanf("%d",&ele);
               p2=insert(p2,ele);
               break;

        case 3:display(p1);
               break;

        case 4:display(p2);
               break;

        case 5:p1=con(p1,p2);
            break;
        
        case 6:return 0;
    }
    goto read;
}


nodeptr insert(nodeptr p,int ele)
{
    nodeptr q;


    q=(nodeptr)malloc(sizeof(struct node));
    q->info=ele;
    q->next='\0';

    if(p=='\0')
    {
        return q;
    }
    else
    {
        q->next=p;
        p=q;
        return p;
    }
}

void display(nodeptr p)
{
    nodeptr cur;
    if(p=='\0')
    {
        printf("the que is empty");
        return ;
    }
    else
    {
        cur=p;
        while(cur!='\0')
        {
            printf("%d",cur->info);
            cur=cur->next;
        }
    }
}

nodeptr con(nodeptr p1,nodeptr p2)
{
    nodeptr cur;
    if(p1=='\0')
    {
        return p2;
    }
    else if(p2=='\0')
    {
        return p1;
    }
    else if(p1=='\0' && p2=='\0')
    {
        return '\0';
    }
    else
    {
        cur=p1;

        while(cur->next!='\0')
        {
            cur=cur->next;
        }

        cur->next=p2;
        return p1;
    }
}