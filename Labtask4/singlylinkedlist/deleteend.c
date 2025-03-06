#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* createnode(int newdata){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=newdata;
    newnode->next=NULL;
    return newnode;
}
int main(){
    struct Node *head=NULL,*tail=NULL;
    struct Node*temp=NULL;
    head=createnode(0);
    head->next=createnode(1);
    head->next->next=createnode(2);
    head->next->next->next=createnode(3);
    temp=tail=head;
    while(temp->next!=0){
        tail=temp;
        temp=temp->next;
    }
    tail->next=0;
    free(temp);
    tail=head;
    while(tail!=0){
        printf("%d ",tail->data);
        tail=tail->next;
    }
}