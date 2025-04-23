#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value)
{
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node* search(struct Node* root, int data)
{

    if (root == NULL || root->data== data)
        return root;
    if (root->data < data)
        return search(root->right, data);
    return search(root->left, data);
}

int main()
{

    struct Node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);

    printf(search(root, 19) != NULL ? "Found\n": "Not Found\n");
    printf(search(root, 80) != NULL ? "Found\n": "Not Found\n");

    return 0;
}
