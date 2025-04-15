#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node * next;
    struct node * prev;
};
struct node *top=0;

int isEmpty()
{
    if(top == 0)
    {
        return 1;
    }
    else{return 0;}
}

void push()
{
    struct node* n = (struct node *)malloc(sizeof(struct node));
    if(n==0)
    {
        printf("STACK OVERFLOW ! CAN'T PUSH ANOTHER ELEMENT \n");
        return ;
    }
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    n->data=data;
    n->next=0;
    n->prev=0;
    if(top==0)
    {
        top = n;
    }
    else
    {
        n->next =top;
        top->prev= n;
        top = n;
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
        struct node* temp = top;
        a = temp->data;
        top = top->next;
        top->prev=0;
        free(temp);
    }
    return a;
}

void display()
{
    struct node* temp = top;
    while(temp!=NULL)
    {
        printf(" %d ",temp->data);
        temp= temp->next;
    }
}

int main(){
    int size;
    // No need to allocate memory for top here, as it is already initialized to 0 globally.
    printf("Enter the size : ");
    scanf("%d",&size);

    for(int i =0;i<size;i++)
    {
        push();
    }

    printf("%d is popped\n",pop());
    printf("%d is popped\n",pop());

    display();
    return 0;
}