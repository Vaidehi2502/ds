#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createnode(int value){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}
struct Node* insertleft(struct Node* root,int value){
    root->left = createnode(value);
    return root->left;
}
struct Node* insertright(struct Node* root,int value){
    root->right=createnode(value);
    return root->right;
}
int height(struct Node*root){
    if(root==NULL){
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    int max = (left_height > right_height) ? left_height : right_height;
        return max+1;
}
int main(){
    struct Node* root = createnode(1);
    insertleft(root, 12);
    insertright(root, 9); 
    insertleft(root->left, 5);
    insertright(root->left, 6);
    printf("%d",height(root));
}
