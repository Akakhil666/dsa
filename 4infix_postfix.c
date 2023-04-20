#include<stdio.h>
#define size 50

struct stack 
{
    int a[size];
    int top;
};

typedef struct stack stack;

void compute(stack *,char [10]);
void push(stack *,char );
char pop(stack *);
int pri(char ); 

int main()
{
    char in[50];
    stack s;
    s.top=-1;

    printf("enter the infix expression");
    scanf("%s",in);

    compute(&s,in);

    return 0;
}

void compute(stack *s,char in[50])
{
    int i,j=0;
    char x,post[50],ch;

    for(i=0;(x=in[i])!='\0';i++)
    {
        if(x=='(')
        {
            push(s,x);
        }

        if(x>='0' && x<='9')
        {
            post[j++]=x;
        }

        if(x=='+'||x=='-'||x=='*'||x=='/')
        {
            if(s->top==-1)
            {
                push(s,x);
            }
            else
            {
                if(pri(x)>pri(s->a[s->top]))
                {
                    push(s,x);
                }
                else
                {
                    post[j++]=pop(s);
                    push(s,x);
                }
            }
        }

        if(x==')')
        {
            while((ch=pop(s))!='(')
            {
                post[j++]=ch;
            }
        }
    }

    while(s->top!=-1)
    {
        post[j++]=pop(s);
    }
    post[j]='\0';

    printf("%s",post);
}

void push(stack *s,char x)
{
    s->a[++s->top]=x;
}

char pop(stack *s)
{
    return s->a[s->top--];
}

int pri(char x)
{
    switch (x)
    {
        case '(':return 0;
        case '+':return 1;
        case '-':return 1;
        case '*':return 2;
        case '/':return 2;
    }
}
