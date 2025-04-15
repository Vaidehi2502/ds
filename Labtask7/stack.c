#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int size;
    int top;
    int *arr;
}stack;
stack *s;

int isFull()
{
    if(s->top == s->size-1)
    {
        return 1;
    }
    else{return 0;}
}

int isEmpty()
{
    if(s->top == -1)
    {
        return 1;
    }
    else{return 0;}
}

void push()
{
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);

    if(isFull())
    {
        printf("STACK OVERFLOW ! CAN'T PUSH ANOTHER ELEMENT \n");
        return ;
    }
    else{
        s->top++;
        s->arr[s->top] = data;
    }

}

int pop()
{
    int a = -1;
    if(isEmpty())
    {
        printf("STACK UNDERFLOW ! CAN'T POP ANOTHER ELEMENT \n");
    }
    else
    {
        a = s->arr[s->top];
        s->top--;
    }
    return a;
}

void display()
{
    int x = s->top;
    while(x>=0)
    {
        printf(" %d ",s->arr[x]);
        x--;
    }
}

int main(){
    int size;
    s =(stack *)malloc(sizeof(stack));
    printf("Enter the size : ");
    scanf("%d",&size);

    s->size = size;
    s->top = -1;
    s->arr = (int *)malloc(s->size*sizeof(int));

    for(int i =0;i<s->size;i++)
    {
        push();
    }

    printf("%d is popped\n",pop());
    printf("%d is popped\n",pop());

    display();
    return 0;
}