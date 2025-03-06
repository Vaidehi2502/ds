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

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL, *tail = NULL;
    struct Node *even = NULL, *odd = NULL, *evenhead = NULL, *oddhead = NULL;

    head = createnode(10);
    head->next = createnode(5);
    head->next->next = createnode(20);
    head->next->next->next = createnode(21);
    head->next->next->next->next = createnode(12);
    head->next->next->next->next->next = createnode(14);
    head->next->next->next->next->next->next = createnode(7);

    tail = head; 
    while (tail != NULL) {
        if (tail->data % 2 == 0) {
            if (evenhead == NULL) {
                even = tail;
                evenhead = tail;
            } else {
                even->next = tail;
                even = even->next;
            }
        } else {
            if (oddhead == NULL) {
                odd = tail;
                oddhead = tail;
            } else {
                odd->next = tail;
                odd = odd->next;
            }
        }
        tail = tail->next;
    }

    if (even != NULL) {
        even->next = NULL;
    }
    if (odd != NULL) {
        odd->next = NULL;
    }

    while (evenhead != NULL) {
        printf("%d ", evenhead->data);
        evenhead = evenhead->next;
    }
    printf("\n");
    while(oddhead!=NULL){
        printf("%d ",oddhead->data);
        oddhead=oddhead->next;
    }

    

    return 0;
}
