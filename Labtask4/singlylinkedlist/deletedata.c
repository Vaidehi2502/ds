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
    int n,num;
    head=createnode(0);
    head->next=createnode(1);
    head->next->next=createnode(2);
    head->next->next->next=createnode(3);
    temp=tail=head;
    scanf("%d",&num);
    for(int i=0;i<n;i++){
        if(temp->data==num){
            tail->next=temp->next;
            free(temp);
            break;
        }
        else{tail=temp;
            temp=temp->next;}
    }
    tail=head;
    while(tail!=0){
        printf("%d ",tail->data);
        tail=tail->next;
    }
}