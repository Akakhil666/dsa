#include<stdio.h>

struct book
{
    char name[10];
    int edi,price;
};

typedef struct book book;

void read(book *,int );
void display(book [10],int );
void compute(book [10],int );

int main()
{
    book b[19];
    int n;

    printf("enter the number of books");
    scanf("%d",&n);

    read(b,n);

    display(b,n);

    compute(b,n);

    return 0;
}

void read(book *b,int n)
{
    int i;

    for(i=0;i<n;i++)
    {
      printf("enter the name edtion and price of book %d",i+1);
      scanf("%s %d %d",(b+i)->name,&(b+i)->edi,&(b+i)->price);
    }
}

void display(book b[10],int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("the name of %d book is %s and editon is %d and price is %d\n",i+1,b[i].name,b[i].edi,b[i].price);
    }
}

void compute(book b[10],int n)
{
    int i,j,high=0;

    for(i=0;i<n;i++)
    {
        if(high<b[i].price)
        {
            high=b[i].price;
            j=i;
        }
    }
    printf("the book with highest price is %s and %d and its price is %d",b[j].name,b[j].edi,b[j].price);
}


