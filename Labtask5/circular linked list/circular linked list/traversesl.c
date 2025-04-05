#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* next;
    int data;
};
struct Node* createnode(int newdata){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=newdata;
    newnode->next=NULL;
}
int main(){
    struct Node* head=createnode(1);
    struct Node* first=createnode(2);
    struct Node* second=createnode(3);
    head->next=first;
    first->next=second;
    second->next=head;
    struct Node* temp;
    temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }
    while(temp!=head); 
}