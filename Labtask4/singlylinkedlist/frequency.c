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
    struct Node *head1,*itr,*temp;
    head1 = createnode(10);
    head1->next = createnode(20);
    head1->next->next = createnode(20);
    head1->next->next->next = createnode(30);
    head1->next->next->next->next = createnode(31);
    head1->next->next->next->next->next = createnode(31);
    temp=head1;
    while(temp!=0&&temp->next!=0){
        itr=temp->next;
        int count=1;
        while(itr!=0&&itr->data==temp->data){
            itr=itr->next;
            count++;
        }
        printf("%d->%d\n",temp->data,count);
        temp->next=itr;
        temp=temp->next;
    }
        temp=head1;
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }

}
