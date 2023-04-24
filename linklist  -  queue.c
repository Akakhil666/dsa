#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};

typedef struct node * nodeptr;

nodeptr insert_front(nodeptr ,int );
nodeptr delete_rear(nodeptr );
void display(nodeptr );

int main()
{
    int ch,ele;
    nodeptr p;
    p='\0';

    read:

    printf("\n1--to insert a ele into que \n2--to delete a ele \n3--to display hte qeu\n4--to exit\n");
    printf("enter the choice");
    scanf("%d",&ch);

    switch (ch)
    {
        case 1:printf("enter the ele to be insertd");
               scanf("%d",&ele);
               p=insert_front(p,ele);
               break;

        case 2:p=delete_rear(p);
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

nodeptr delete_rear(nodeptr p)
{
    
    nodeptr cur,prev;

    if(p=='\0')
    {
        printf("the que is empty");
        return '\0';
    }
    else if(p->next=='\0')
    {
        printf("the del ele is %d",p->info);
        free(p);
        return '\0';
    }
    else
    {
        cur=p;
        prev='\0';

        while(cur->next!='\0')
        {
            prev=cur;
            cur=cur->next;
        }
        printf("the deleted ele is %d",cur->info);
        free(cur);
        prev->next='\0';
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
