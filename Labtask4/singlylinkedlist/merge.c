#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createnode(int newdata) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = NULL;
    return newnode;
}

int main() {
    struct Node *head1 = NULL, *head2=NULL,*tail1=NULL,*tail2=NULL,*tail=NULL;
    struct Node *linkedlist = NULL;
    head1 = createnode(10);
    head1->next = createnode(20);
    head1->next->next = createnode(30);
    head1->next->next->next = createnode(40);
    head2 = createnode(5);
    head2->next = createnode(12);
    head2->next->next = createnode(25);
    head2->next->next->next = createnode(38);
    tail1=head1;
    while(tail1->next!=0){
        tail1=tail1->next;
    }
    tail1->next=head2;
    tail1=head1;
    while(tail1!=0){
        printf("%d ",tail1->data);
        tail1=tail1->next;
    }
}