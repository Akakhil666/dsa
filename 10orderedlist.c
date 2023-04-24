#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};
typedef struct node * nodeptr;

nodeptr insert(nodeptr ,int );
void display(nodeptr );

int main()
{
    int ch,ele;
    nodeptr p;
    p='\0';

    read:

    printf("\n1--to enter the ele \n2--to display\n3--to -exit\n");
    printf("enter the choice");
    scanf("%d",&ch);

    switch (ch)
    {
        case 1:printf("enter the ele to be inserted ");
               scanf("%d",&ele);
               p=insert(p,ele);
               break;

        case 2:display(p);
               break;

        case 3:return 0;
    }
    goto read;
}

nodeptr insert(nodeptr p,int ele)
{
    nodeptr q,cur,prev;
    q=(nodeptr)malloc(sizeof(struct node));
    q->info=ele;
    q->next='\0';

    if(p=='\0')
    {
        return q;
    }
    else if(ele<=p->info)
    {
        q->next=p;
        p=q;
        return p;
    }
    else
    {
        cur=p;
        prev='\0';

        while(cur!='\0')
        {
           if(ele>cur->info)
           {
               prev=cur;
               cur=cur->next;
           }
           else
           {
               prev->next=q;
               q->next=cur;
               return p;
           }
       }
       prev->next=q;
       return p;
    }
}

void display(nodeptr p)
{
    nodeptr cur;

    if(p=='\0')
    {
        printf("the ll is empty");
    }
    else
    {
        cur=p;

        while(cur!='\0')
        {
            printf("%d ",cur->info);
            cur=cur->next;
        }
    }
}