#include<stdio.h>
#define size 5

struct queue
{
    int a[size];
    int front,rear;
};

typedef struct queue que;

void insert(que *,int );
int delete(que*);
void display(que);

int main()
{
    int ch,ele;
    que q;

    q.front=0;
    q.rear=-1;

    read:

    printf("\n1--to enter a ele\n2--to delete a ele \n3--to display\n4--to exit\n");
    printf("enter lyoure choice");
    scanf("%d",&ch);

    switch (ch)
    {
        case 1:printf("enter the ele ti be inserted");
               scanf("%d",&ele);
               insert(&q,ele);
               break;

        case 2:ele=delete(&q);
               if(ele!=-1)
               printf("the deleted ele is %d",ele);
               break;

        case 3:display(q);
               break;

        case 4:return 0;
    }
    goto read;
}


void insert(que *q,int ele)
{
    int i;
    if(q->rear==size-1)
    {
        printf("the que is full");
    }
    else
    {
        i=q->rear;
        while(i>=q->front)
        {
            if(ele<q->a[i])
            {
                q->a[i+1]=q->a[i];
                i--;
            }
            else
            break;
        }

        q->a[i+1]=ele;
        q->rear++;
    }
}

int delete(que *q)
{
    if(q->front>q->rear)
    {
        printf("teh que is empty");
        return -1;
    }
    else
    {
        return q->a[q->front++];
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
        for(i=q.front;i<=q.rear;i++)
        {
            printf("%d",q.a[i]);
        }
    }
}
