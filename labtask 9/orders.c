#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

void inorder(struct Node*root){
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);

}
void postorder(struct Node* root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void perorder(struct Node* root){
    if(root==NULL)return;
    printf("%d ",root->data);
    perorder(root->left);
    perorder(root->right);
}

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
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
    printf("The inorder of the tree is:\n");
    inorder(root);
    printf("\n");
    printf("The postorder of the tree is:\n");
    postorder(root);
    printf("\n");
    printf("The perorder of the tree is:\n");
    perorder(root);
  
}