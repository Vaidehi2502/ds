#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value) {
    struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}


struct Node* insert(struct Node* node, int data) {
    if (node == NULL)
        return newNode(data);
    
    if (node->data == data)
        return node;

    if (node->data <data)
        node->right = insert(node->right, data);

    else
        node->left = insert(node->left, data);
    return node;
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct Node* root = newNode(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    inorder(root);

    return 0;
}
