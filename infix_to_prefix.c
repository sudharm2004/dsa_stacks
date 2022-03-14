#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int top(struct stack* e)
{
    return e->arr[e->top];
}

int precedence(char a)
{
    if (a=='*'||a=='/')
    {
        return 3;
    }
    else if(a=='+'||a=='-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void transeversal(struct stack* e)
{
    for (int i = 0; i < e->top+1; i++)
    {
        printf("%c\n",e->arr[i]);
    }    
}

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

char pop(struct stack* e)
{
    if(empty_check(e))
    {
        printf("Stack underflow!!");
        return -1;
    }
    else
    {
    char val=e->arr[e->top];
    e->top--;  
    return val;
    }
}

int ifoperator(char a)
{
    if (a=='-'||a=='+'||a=='*'||a=='/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char* infixtopostfix(char *infix)
{
    struct stack* e=(struct stack*)malloc(sizeof(struct stack));
    e->size=10;
    e->top=-1;
    e->arr=(char*)malloc(e->size*sizeof(char));
    int i=0,j=0;
    char* postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));
    while (infix[i]!='\0')
    {
        if (ifoperator(infix[i])==0)
        {
            postfix[j]=infix[i];
            // printf("postfix inserted at %d is %c\n",j,po[j]);
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i])>precedence(top(e)))
            {
                push(e,infix[i]);
                // printf("/stackat %d is %c\n",e->top,e->arr[e->top]);
                i++;
            }
            else
            {
                postfix[j]=pop(e);
                j++;
            }
        }
    }   

    while (empty_check(e)==0)
    {
        postfix[j]=pop(e);
        // printf("popped and went into postfix%c\n",po[j]);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
    
int main()
{
    int i=0;
    char infix[30]="x-y/z-k*d";
    printf("postfix is %s",infixtopostfix(infix));
    return 0;
}