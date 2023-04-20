#include<stdio.h>
#define size 10
struct stack
{
    char a[size];
    int top;
};

typedef struct stack stack;

int check(stack *,char [10]);
void push(stack *,char );
char pop(stack *);


int main()
{
    char word[10];
    int x;
    stack s;

    s.top=-1;

    printf("enter the word xcy");
    scanf("%s",word);

    printf("%s",word);

    x=check(&s,word);

    if(x==0)
    {
        printf("the word is in xcy form");
        return 0;
    }
    printf("the word is not in xcy form");
    return 0;
}

int check (stack *s,char word[10])
{
    int i,j;
    for(i=0;word[i]!='c';i++)
    {
        if(word[i]=='a'||word[i]=='b')
        {
            push(s,word[i]);
        }
    }

    for(j=i+1;word[j]!='\0';j++)
    {
        if(pop(s)!=word[j])
        {
            return 1;
        }
    }
    if(s->top!=-1)
    {
        printf("x is greater than y");
        return 1;
    }
    return 0;
}

void push(stack *s,char word)
{
    if(s->top==size-1)
    {
        printf("the stack is full");
    }
    else
    {
        s->a[++s->top]=word;
    }
}

char pop(stack *s)
{
    if(s->top==-1)
    {
        printf("y is greater than x");
        return 1;
    }
    else
    {
        return s->a[s->top--];
    }
}


