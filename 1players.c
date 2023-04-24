#include<stdio.h>

struct player
{
    char name[10];
    int s1,s2,s3;
};

typedef struct player player;

void read(player *,int );
void display(player [10],int );
void compute(player [10],int );

int main()
{
    player p[10];
    int n;

    printf("enter the number of players");
    scanf("%d",&n);

    read(p,n);

    display(p,n);

    compute(p,n);

    return 0;
}

void read(player *p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
       printf("enter the name and score of playre %d in 3 matches",i+1);
       scanf("%s %d %d %d",(p+i)->name,&(p+i)->s1,&(p+i)->s2,&(p+i)->s3);
    }
}

void display(player p[10],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("the name of %d player is %s and score in 3 matches is %d %d %d\n",i+1,p[i].name,p[i].s1,p[i].s2,p[i].s3);
    }
}

void compute(player p[10],int n)
{
    int i,sum=0,avg=0;
    for(i=0;i<n;i++)
    {
        sum=p[i].s1+p[i].s2+p[i].s3;
        avg=sum/3;
        printf("the avg score of palyer %d is %d\n",i+1,avg);
    }
}