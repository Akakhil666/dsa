#include<stdio.h>
#define size 5
struct queue
{
    int a[size];
    int front,rear;
};

typedef struct queue que;

void insert_front(que *,int );
void insert_rear(que *,int );
int delete_front(que *);
int delete_rear(que *);
void display(que);

int main()
{
    int ch,ele;
    que q;

    q.front=0;
    q.rear=-1;

    read:

    printf("\n1--to insert from front\n2--to inert at rear\n3--to delete at front\n4--to delete at rear\n5--to display\nto exit");
    printf("enter your choice");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:printf("enter the ele to be added ");
               scanf("%d",&ele);
               insert_front(&q,ele);
               break;

        case 2:printf("enter the ele to be added ");
               scanf("%d",&ele);
               insert_rear(&q,ele);
               break;

        case 3:ele=delete_front(&q);
               if(ele!=-1)
               printf("the deleted ele is %d",ele);
               break;

        case 4:ele=delete_rear(&q);
               if(ele!=-1)
               printf("the deleted ele is %d",ele);
               break;      

        case 5:display(q);
               break;

        case 6:return 0; 
    }
    goto read;
}

void insert_front(que *q,int ele)
{
    if(q->front==0)
    {
        printf("the que is full");
    }
    else
    {
        q->a[--q->front]=ele;
    }
}

void insert_rear(que *q,int ele)
{
    if(q->rear==size-1)
    {
        printf("the que is full");
    }
    else
    {
        q->a[++q->rear]=ele;
    }
}

int delete_front(que *q)
{
    if(q->front>q->rear)
    {
        printf("the que is empty");
        return -1;
    }
    else
    {
        return q->a[q->front++];
    }
}

int delete_rear(que *q)
{
    if(q->front>q->rear)
    {
        printf("hte que is empty");
        return -1;
    }
    else{
        return q->a[q->rear--];
    }
}

void display(que q)
{
    int i;
    if(q.front>q.rear)
    {
        printf("the que is empty");
    }
    else
    {
        for(i=q.rear;i>=q.front;i--)
        {
            printf("%d",q.a[i]);
        }
    }
}
