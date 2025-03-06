#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createnode(int Data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=Data;
    newnode->next=NULL;
    return newnode;
}
int main(){
    struct Node* head,*tail;
    int length;
    head=tail=NULL;
    head=createnode(0);
    head->next=createnode(1);
    head->next->next=createnode(2);
    head->next->next->next=createnode(3);
    tail=head;
    while(tail!=0){
        length++;
        tail=tail->next;
    }
    printf("%d",length);
}