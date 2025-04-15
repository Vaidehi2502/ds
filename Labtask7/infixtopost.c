#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int size;
    int top;
    char *arr;
}stack;
stack* s = NULL;
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

void push(char c)
{
    if(isFull())
    {
        printf("STACK OVERFLOW ! CAN'T PUSH ANOTHER ELEMENT \n");
        return ;
    }
    else{
        s->top++;
        s->arr[s->top] = c;
    }

}

int pop()
{
    char a;
    if(isEmpty())
    {
        printf("STACK UNDERFLOW ! CAN'T POP ANOTHER ELEMENT \n");
    }
    else
    {
        a = s->arr[s->top];
        s->top--;
        return a;
    }
    
}

void display()
{
    int x = s->top;
    while(x>=0)
    {
        printf(" %c ",s->arr[x]);
        x--;
    }
}
int isOperator(char c)
{
    if(c=='*' || c=='/' || c=='^' || c=='+' || c=='-')
    {return 1;}
    else{return 0;}
}
int precedence(char c)
{
    if(c=='^')
    {return 3;}
    else if(c=='*' || c=='/')
    {return 2;}
    else if(c=='+' || c=='-')
    {return 1;}
    else
    {return 0;}
}
char stackTop()
{
    return s->arr[s->top];
}
char* intopo(char * infix)
{
    s = (stack*)malloc(sizeof(stack));
    s->size = 20;
    s->top=-1;
    s->arr=(char *)malloc(s->size*sizeof(char));
    char* Postfix =(char *)malloc(strlen(infix+1)*sizeof(char));
    int i =0;//Infix Scanner
    int j=0;//Postfix Scanner
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            Postfix[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i])>precedence(stackTop()))
            {
                push(infix[i]);
                i++;
            }
            else{
                Postfix[j]=pop();
                j++;
            }
        }
    }

    while(!isEmpty())
    {
        Postfix[j]=pop();
        j++;
    }
    Postfix[j]='\0';
    return Postfix;

}

int main(){
    char* infix ="K+L-M*N+O^P*W/U/V*T+Q";

    printf("The PostFix of the Given Infix :  %s",intopo(infix));
    return 0;
}