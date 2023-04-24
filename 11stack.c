#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node* next;
};

typedef struct node * nodeptr;

nodeptr insert_front(nodeptr ,int );
nodeptr delete_front(nodeptr );
void display(nodeptr );

int main()
{
    int ch,ele;
    nodeptr p;
    p='\0';

    read:

    printf("\n1--to push an ele ti stack\n2--to pop a ele from stack\n3--to displaly stack\n4--to exit\n");
    printf("enter your choice ");
    scanf("%d",&ch);

    switch (ch)
    {
        case 1:printf("enter the ele to be pushed");
               scanf("%d",&ele);
               p=insert_front(p,ele);
               break;

        case 2:p=delete_front(p);
               break;
            
        case 3:display(p);
               break;

        case 4:return 0;
    }
    goto read;
}

nodeptr insert_front(nodeptr p,int ele)
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

nodeptr delete_front(nodeptr p)
{
    nodeptr q;

    if(p=='\0')
    {
        printf("the stack is empty");
        return '\0';
    }
    else if(p->next=='\0')
    {
        printf("the poped ele is %d",p->info);
        free(p);
        return '\0';
    }
    else
    {
        q=p;
        p=p->next;
        printf("the poped ele is %d",q->info);
        free(q);
        return p;
    }
}

void display(nodeptr p)
{
    nodeptr cur;
    if(p=='\0')
    {
        printf("the stack is empty");
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