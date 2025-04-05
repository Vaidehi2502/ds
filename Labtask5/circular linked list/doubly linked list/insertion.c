#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* next;
    struct Node* prev;
    int data;
};

struct Node* createnew(int newdata){
    struct Node* Newnode=(struct Node*)malloc(sizeof(struct Node));
    Newnode->data=newdata;
    Newnode->next=NULL;
    Newnode->prev=NULL;
    return Newnode;
}
void insertbegg( struct Node **head,int data){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    if(*head==NULL){
        *head=newnode;
        return;
    }
    else{
        newnode->next=*head;
        (*head)->prev=newnode;
        *head=newnode;
    }
}
void insertend(struct Node **head,int data){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    if(*head==NULL){
        newnode->prev = NULL;
        *head = newnode;
        return;
    }
    else{
       struct Node* temp = *head;
        while(temp->next!=0){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}
void print(struct Node *head){
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void specific(struct Node **head,int data,int n){
    int i=1;
    struct Node* temp = *head;
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    if(n==1){
        insertbegg(head,data);
    }
    else{
        newnode->data=data;
        newnode->next=NULL;
        while(i<n-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;;
        temp->next=newnode;
        newnode->prev=temp;
    }
}
int main(){
    struct Node* Head=createnew(0);
    struct Node*first=createnew(1);
    struct Node*second=createnew(2);
    Head->next=first;
    first->prev=Head;
    first->next=second;
    second->prev=first;
    second->next=NULL;
    printf("Linked list before operation:");
    print(Head);
    printf("Linked list after insertion at begging operation:");
    insertbegg( &Head,10);
    print(Head);
    printf("Linked list after insertion at ending operation:");
    insertend(&Head,20);
    print(Head);
    int n;
    scanf("%d",&n);
    printf("Linked List after the operation:");
    specific(&Head,30,n);
    print(Head);
}
