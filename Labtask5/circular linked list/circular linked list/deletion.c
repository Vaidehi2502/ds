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
void deletebegg(struct Node** head) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    last->next = (*head)->next;

    *head = (*head)->next;
    free(temp);
}
void deleteend(struct Node**head){
    struct Node* temp=*head;
    struct Node* last;
    while(temp->next->next!=*head){
        temp=temp->next;
    }
    last=temp->next;
    temp->next=*head;
    free(last);

}
void deletespecific(struct Node** head,int num){
    struct Node* temp=head;
    struct Node* last;
    int i=1;
    while(i<num){
        temp=temp->next;
        last=temp;
    }
    free(last);
}

void print(struct Node* head) {
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
    struct Node* head=createnode(1);
    struct Node* first=createnode(2);
    struct Node* second=createnode(3);
    struct Node* third=createnode(4);
    struct Node* fourth=createnode(5);
    head->next=first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=head;
    print(head);
    //deletebegg(&head);
    printf("\n");
    //print(head);
    deleteend(&head);
    printf("\n");
    print(head);
    
}