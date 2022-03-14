#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void transversal(struct  node *ptr)
{
    while (ptr!=NULL)
    {
        printf("Element:-%d\n",ptr->data);
        ptr=ptr->next;
    }
}

int empty_check(struct node* top)
{
    if (top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int full_check(struct node* top)
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    if (p==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node* push(struct node* top,int data)
{
    if (full_check(top))
    {
        printf("Stack overflow!!!");
    }
    else
    {
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=top;
    return ptr;
    }
}

struct node* pop(struct node* top)
{
    struct node* ptr=top->next;
    free(top);
    return ptr;
}


void peek(struct node* top, int index)
{
    for (int i = 0; i < index-1&& top!=NULL; i++)
    {
        top=top->next;
    }
    if (top==NULL)
    {
        printf("The given index does not exist!!!\n");
    }
    else
    {
        printf("The value at given index %d is %d\n",index,top->data);
    }
}

int stack_top(struct node* top)
{
    return top->data;
}

int stack_bottom(struct node* top)
{
    while (top->next!=NULL)
    {
        top=top->next;
    }
    return top->data;
}

int main()
{   
    struct node* top=NULL;
    
    printf("BEFORE:-\n");
    top=push(top,35);
    top=push(top,45);
    top=push(top,55);
    top=push(top,65);
    top=push(top,75);
    printf("%d",(top->next)->data);
    transversal(top);
    top=pop(top);
    printf("AFTER:-\n");
    transversal(top);
    peek(top,1);
    //printf("The stacktop is %d\n",stack_top(top));
    printf("The stackbottom is %d\n",stack_bottom(top));
    empty_check(top);
}