#include<iostream>
using namespace std;

struct Node{

    int data;
    Node*left = NULL;
    Node*right = NULL;

    Node(int val){
        data = val;
    }
};

/* Balanced binary tree : For each node the difference between
the heights of the left subtree and right subtree <= 1
=> mod(left ht -  right ht)<=1 */

int height(Node* root){

    if(root == NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh) + 1;
}

bool isBalanced(Node* root){

    if(root == NULL){
        return true;
    }

    if(isBalanced(root->left) == false){
        return false;
    }
    if(isBalanced(root->right)==false){
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh)<=1){
        return true;
    } else{
        return false;
    }

}
bool optimizedisBalanced(Node* root, int* height){

    if(root == NULL){
        return true;
    }

    int lh = 0; rh = 0;
    if(isBalanced(root->left, &lh)==false){
        return false;
    }
    if(isBalanced(root->right, &rh)==false){
        return false;
    }

    *height = max(lh,rh) + 1;
    if(abs(lh-rh)<=1){
        return true;
    }else{
        return false;
    }
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    if(isBalanced(root)){
        cout<<"Balanced Tree"<<endl;
    }
    else{
        cout<<"Unbalanced Tree"<<endl;
    }

    int height = 0;
    if(optimizedisBalanced(root,&height)==true){
        cout<<"Balanced Tree"<<endl;
    }
    else{
        cout<<"Unbalanced Tree"<<endl;
    }
    return 0;
}
