#include<iostream>
#include<queue>
using namespace std;

struct Node{

    int data;
    Node*left = NULL;
    Node*right = NULL;

    Node(int val){
        data = val;
    }
};

void flatten(Node* root){

    if( root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    if(root->left!=NULL){
        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* tail = root->right;
        while(tail->right != NULL){
            tail = tail->right;
        }

        tail -> right = temp;
    }

    flatten(root->right);
}

void inorderPrint(Node* root){

    if(root == NULL){
        return;
    }

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){

    Node* root = new Node(4);
    root->left = new Node(9);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    
    flatten(root);
    inorderPrint(root);
    cout<<"\n";
    return 0;
}