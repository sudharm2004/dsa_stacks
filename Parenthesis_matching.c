#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int empty_check(struct stack* e)
{
    if ((e->top)==-1)
    {
        return 1;
    }
    else
    {
    return 0;
    }
}

int full_check(struct stack* e)
{
    if (e->top==e->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack* e,char data)
{
    if(full_check(e))
    {
        printf("!!Warning:-stack overflow!!\n");
    }
    else
    {
    e->top++;
    e->arr[e->top]=data;
    }
}

void pop(struct stack* e)
{
    if(empty_check(e))
    {
        printf("Stack underflow!!");
    }
    else
    {
    e->top--;  
    }
}

int parenthesismatch(char *exp,int size)
{
    struct stack *e=(struct stack *)malloc(sizeof(struct stack)); 
    e->size= size;
    e->top=-1;
    e->arr=(char *)malloc(e->size*sizeof(char));   

   for (int i = 0; i < exp[i]!='\0'; i++)
   {
        if (exp[i]=='(')
        {
            push(e,'(');
        }
        else if(exp[i]==')')
        {
            if (empty_check(e))
            {
                return 0;
            }
            else
            {
                pop(e);
            }
        }
   }
   if (empty_check(e))
   {
       return 1;
   }
   else
   {
       return 0;
   }
}

int main()
{
    char exp[30]="(20-5)*(30+15)/(500+450)";
    int n=strlen(exp);
    if (parenthesismatch(exp,n)==1)
    {
        printf("THe given equation is balanced");
    }
    else
    {
        printf("The given equation is not balanced");
    }
    return 0;
}