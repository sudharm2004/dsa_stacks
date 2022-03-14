#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

void transeversal(struct stack* e)
{
    for (int i = 0; i < e->top+1; i++)
    {
        printf("%d\n",e->arr[i]);
    }    
}

void peek(struct stack* e,int index)
{
    printf("We index from top to bottom in stack\n");
    printf("Using the peek function\n");
    int a=e->top-index+1; 
    printf("The value at given index is %d\n",e->arr[a]);
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

int top(struct stack* e)
{
    return e->arr[e->top];
}

int bottom(struct stack* e)
{
    return e->arr[0];
}

void push(struct stack* e,int data)
{
    if((full_check(e))==1)
    {
        printf("!!Warning:-stack overflow!!\n");
    }
    else
    {
    e->top++;
    e->arr[e->top]=data;
    }
}

int pop(struct stack* e)
{
    if(empty_check(e)==1)
    {
        printf("!!Warning:-stack underflow!!\n");
    }
    else
    {
    int val;
    val=e->arr[e->top];
    e->top--;  
    return val;//returning the value that is popped
    }
}

int main()
{
    struct stack* e=(struct stack*)malloc(sizeof(struct stack));
    e->size=80;
    e->arr=(int*)malloc((e->size)*sizeof(int));
    e->top=-1;

    // int check=empty_check(e);

    // if (check==1)
    // {
    //     printf("The stack is empty!!");
    // }
    // else
    // {
    //     printf("The stack is not empty!!");
    // }

    // check=full_check(e);

    // if (check==1)
    // {
    //     printf("The stack is full!!");
    // }
    // else
    // {
    //     printf("The stack is not full!!");
    // }

    push(e,5);
    push(e,15);
    push(e,25);
    push(e,35);
    peek(e,4);
    printf("Before:-\n");
    transeversal(e);
    pop(e);
    printf("After:-\n");
    transeversal(e);
    printf("The stack top is %d",top(e));
    printf("The stack bottom is %d",bottom(e));
    return 0;
}