#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node* right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int countleaf(struct Node*root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL&&root->right==NULL){
        return 1;
    }
    return countleaf(root->left)+ countleaf(root->right);
}
struct Node* insertLeft(struct Node* root, int value) {
    root->left = createNode(value);
    return root->left;
  }
  
  struct Node* insertRight(struct Node* root, int value) {
    root->right = createNode(value);
    return root->right;
  }
int main(){
    struct Node* root = createNode(1);
    insertLeft(root, 12);
    insertRight(root, 9);
  
    insertLeft(root->left, 5);
    insertRight(root->left, 6);
    printf("%d",countleaf(root));
}