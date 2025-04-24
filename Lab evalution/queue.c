#include <stdio.h>
#include <stdlib.h>

#define MAX 1000 

struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

struct QueueNode* newNode(int data) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int data) {
    struct QueueNode* temp = newNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
void displayQueue(struct Queue* q) {
    struct QueueNode* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int findFirstNonRepeated(struct Queue* q) {
    int freq[MAX] = {0};
    struct QueueNode* temp = q->front;
    while (temp != NULL) {
        freq[temp->data]++;
        temp = temp->next;
    }
    temp = q->front;
    while (temp != NULL) {
        if (freq[temp->data] == 1)
            return temp->data;
        temp = temp->next;
    }

    return -1;
}

int main() {
    struct Queue* q = createQueue();

    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 3);
    enqueue(q, 2);
    enqueue(q, 2);

    displayQueue(q);

    int result = findFirstNonRepeated(q);
    if (result != -1)
        printf("First non-repeated number is: %d\n", result);
    else
        printf("No non-repeated number found.\n");

    return 0;
}
