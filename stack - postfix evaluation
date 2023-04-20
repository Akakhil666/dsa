#include<stdio.h>
#define size 10

struct stack 
{
    float a[size];
    int top;
};

typedef struct stack  stack;

float eval(stack *,char [10]);
float compute(float ,float ,char );
void push(stack *,float );
float pop(stack *);


int main()
{
    float x;
    stack s;
    char postfix[10];

    s.top=-1;

    printf("enter the postfix expression");
    scanf("%s",postfix);

    x=eval(&s,postfix);

    printf("the result is %f",x);

    return 0;
}

float eval(stack *s,char postfix[10])
{
    int i;
    float ope1,ope2,res;
    char ch;
    for(i=0;(ch=postfix[i])!='\0';i++)
    {
        if(ch>='0'&&ch<='9')
        {
            push(s,ch-'0');
        }

        else
        {
            ope2=pop(s);
            ope1=pop(s);
            res=compute(ope1,ope2,ch);
            push(s,res);
        }
    }
    return pop(s);
}

float compute(float ope1,float ope2,char ch)
{
    switch (ch)
    {
        case '+':return ope1+ope2;
        case '-':return ope1-ope2;
        case '*':return ope1*ope2;
        case '/':return ope1/ope2;
    }
}


void push(stack *s,float ch)
{
    s->a[++s->top]=ch;
}

float pop(stack *s)
{
    return s->a[s->top--];
}
