#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct ListNode {
    int data;
    struct ListNode* next;
};

struct TreeNode* newTreeNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL)
        return newTreeNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}
struct ListNode* newListNode(int data) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->data = data;
    node->next = NULL;
    return node;
}

void inorderToList(struct TreeNode* root, struct ListNode** headRef, struct ListNode** tailRef) {
    if (root == NULL)
        return;

    inorderToList(root->left, headRef, tailRef);

    struct ListNode* newNode = newListNode(root->data);
    if (*headRef == NULL) {
        *headRef = *tailRef = newNode;
    } else {
        (*tailRef)->next = newNode;
        *tailRef = newNode;
    }

    inorderToList(root->right, headRef, tailRef);
}

int getKthElement(struct ListNode* head, int k) {
    int count = 1;
    while (head != NULL) {
        if (count == k)
            return head->data;
        head = head->next;
        count++;
    }
    return -1; 
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 20);
    insert(root, 8);
    insert(root, 22);
    insert(root, 4);
    insert(root, 12);
    insert(root, 10);
    insert(root, 14);

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    inorderToList(root, &head, &tail);
    int k;
    scanf("%d",&k);
    int kth = getKthElement(head, k);
    if (kth != -1)
        printf("The %d-th smallest element is %d\n", k, kth);
    else
        printf("The list has fewer than %d elements.\n", k);

    return 0;
}
