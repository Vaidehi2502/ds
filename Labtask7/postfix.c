#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct node
{
    int size;
    int top;
    int *arr; // Change to int for evaluation
} stack;

stack *s = NULL;

int isFull()
{
    return s->top == s->size - 1;
}

int isEmpty()
{
    return s->top == -1;
}

void push(int value)
{
    if (isFull())
    {
        printf("STACK OVERFLOW! CAN'T PUSH ANOTHER ELEMENT\n");
        return;
    }
    s->top++;
    s->arr[s->top] = value;
}

int pop()
{
    if (isEmpty())
    {
        printf("STACK UNDERFLOW! CAN'T POP ANOTHER ELEMENT\n");
        return -1; // Return an invalid value
    }
    int value = s->arr[s->top];
    s->top--;
    return value;
}

int evaluatePostfix(char *postfix)
{
    s = (stack *)malloc(sizeof(stack));
    s->size = 20;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0'); 
        }
        else
        {
            int val2 = pop();
            int val1 = pop();
            switch (postfix[i])
            {
            case '+':
                push(val1 + val2);
                break;
            case '-':
                push(val1 - val2);
                break;
            case '*':
                push(val1 * val2);
                break;
            case '/':
                push(val1 / val2);
                break;
            case '^':
                push((int)pow(val1, val2));
                break;
            default:
                printf("Invalid operator encountered: %c\n", postfix[i]);
                break;
            }
        }
    }

    return pop();
}

int main()
{
    char postfix[] = "23*54*+9-"; // Example postfix expression

    printf("The result of the postfix evaluation is: %d\n", evaluatePostfix(postfix));
    return 0;
}