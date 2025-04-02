#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* next;
    struct Node* prev;
    int data;
};
struct Node*createnode(int newdata){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=newdata;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
int main(){
    struct Node* Head,*first,*second,*third;
    Head=NULL;
    Head=createnode(1);
    first=createnode(2);
    second=createnode(3);
    third=createnode(4);
    Head->next=first;
    first->prev=Head;
    first->next=second;
    second->prev=first;
    second->next=third;
    third->prev=second;
    third->next=NULL;
    struct Node* temp=NULL;
    temp=Head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

}