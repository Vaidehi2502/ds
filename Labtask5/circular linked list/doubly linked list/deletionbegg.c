#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *next;
    struct Node *prev;
    int data;
};

struct Node *createnode(int Data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->next=NULL;
    newnode->data=Data;
    newnode->prev=NULL;
}

void deleteatstart(struct Node **head){
    struct Node * temp=(struct Node*)malloc(sizeof(struct Node));
    temp=*head;
    *head=temp->next;
    free(temp);
}
void deleteend(struct Node **head){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;    
    }
    temp->prev->next=NULL;
    free(temp);
}
void specific(struct Node **head,int n){
    int i=1;
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=*head;
    while(i<=n){
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    free(temp);
}
void print(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main(){
    struct Node *head=createnode(1);
    struct Node *first=createnode(2);
    struct Node* second=createnode(3);
    struct Node* third =createnode(4);
    head->next=first;
    first->prev=head;
    first->next=second;
    second->prev=first;
    second->next=third;
    third->prev=second;
    print(head);
    int n;
    scanf("%d",&n);
    specific(&head,n);
    print(head);
    deleteatstart(&head);
    print(head);
    deleteend(&head);
    print(head);
}