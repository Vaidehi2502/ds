#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* next;
    int data;
};
struct Node* createnode(int data){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node*));
    newnode->data=data;
    newnode->next=NULL;
}
void insertionbegg(struct Node **head,int num){
    struct Node* temp;
    struct Node* newNode=createnode(num);
    while (temp->next != *head) {
        temp = temp->next;
    }
    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}
void insertionend(struct Node** head, int num){
    struct Node*temp;
    struct Node* newnode=createnode(num);
    while(temp->next!=*head){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=*head;
    
}
void insertionspecific(struct Node **head,int num,int n){
    struct Node* temp;
    struct Node* newnode=createnode(num);
    temp=*head;
    int i=0;
    while(i<n-2){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void traverseCircularList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
int main(){
    struct Node * head= createnode(0);
    int num;
    struct Node*first=createnode(1);
    struct Node* second=createnode(2);
    struct Node* third=createnode(3);
    head->next=first;
    first->next=second;
    second->next=third;
    third->next=head;
    scanf("%d",&num);
    insertionbegg(&head,num);    
    traverseCircularList(head);
    int num2;
    scanf("%d",&num2);
    insertionend(&head,num2);
    traverseCircularList(head);
    int i;
    printf("\nThe position:");
    scanf("%d",&i);
    insertionspecific(&head,num,i);
    traverseCircularList(head);
}