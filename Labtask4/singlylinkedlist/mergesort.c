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
int main(){
    struct Node *head1 = NULL, *head2=NULL,*temp1=NULL,*temp2=NULL,*head=NULL,*temp=NULL;
    head1 = createnode(2);
    head1->next = createnode(4);
    head1->next->next = createnode(8);
    head1->next->next->next = createnode(10);
    head2 = createnode(1);
    head2->next = createnode(3);
    head2->next->next = createnode(3);
    head2->next->next->next = createnode(11);
    head2->next->next->next->next = createnode(14);
    temp1=head1;
    temp2=head2;
    if(temp1->data<temp2->data){
        head=temp1;
        temp1=temp1->next;
    }
    else{
        head=temp2;
        temp2=temp2->next;
    }
    temp=head;
    while(temp1!=NULL&&temp2!=NULL){
        if (temp1->data < temp2->data) {
            temp->next = temp1;
            temp1 = temp1->next;
        } 
        else {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    if (temp1 != NULL) {
        temp->next = temp1;
    } else {
        temp->next = temp2;
    }
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}
