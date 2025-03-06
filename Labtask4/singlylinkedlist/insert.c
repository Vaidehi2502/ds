#include<stdio.h>
#include<malloc.h>
// addition at beg,endand at specific pos

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
    struct Node* head,*tail;
    int input;
    head=tail=NULL;
    head=createnode(0);
    head->next=createnode(1);
    head->next->next=createnode(2);
    head->next->next->next=createnode(3);
    struct Node*node=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data you want to insert:");
    scanf("%d",&node->data);
    node->next=head;
    head=node;
    tail=head;
    while(tail!=NULL){
        printf("%d ",tail->data);
        tail=tail->next;
    }
    printf("\n");
//at the end
    struct Node* Node=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data you want to insert:");
    scanf("%d",&Node->data);
    Node->next=NULL;
    tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=Node;
    tail=head->next;
    while(tail!=NULL){
        printf("%d ",tail->data);
        tail=tail->next;
    }
    printf("\n");
//at a specific position
int n;
    struct Node* NODE=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data you want to insert:");
    scanf("%d",&NODE->data);
    printf("Enter the position where you want to inser:");
    scanf("%d",&n);
    tail=head;
    for(int i=0;i<n-1;i++){
        tail=tail->next;
    }
    NODE->next=tail->next;
    tail->next=NODE;
    tail=head->next;
    while(tail->next!=NULL){
        printf("%d ",tail->data);
        tail=tail->next;
    }
}


