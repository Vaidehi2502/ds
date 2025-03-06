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
    int num,index;
    scanf("%d",&num);
    head=createnode(1);
    head->next=createnode(2);
    head->next->next=createnode(3);
    head->next->next->next=createnode(4);
    temp=tail=head;
    for(int i=1;i<=4;i++){
        if(tail->data==num){
            index=i;
        }
        tail=tail->next;
    }
    printf("%d\n",index);
    tail=head;
    for(int i=1;i<index-1;i++){
        tail=tail->next;
    }
    temp=tail->next;
    tail->next=temp->next;
    free(temp);
    tail=head;
    while(tail!=0){
        printf("%d ",tail->data);
        tail=tail->next;
    }
}