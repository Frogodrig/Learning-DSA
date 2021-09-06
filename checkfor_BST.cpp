#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left = NULL;
    Node* right = NULL;
    Node(int val){
        data = val;
    }
};

bool isBST(Node* root, Node* min=NULL, Node* max=NULL){

    if(root == NULL){
        return true;
    }

    if(min != NULL && root->data <= min->data){
        return false;
    }

    if(max != NULL && root->data >= max ->data){
        return false;
    }

    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);
    return leftValid and rightValid;
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    if(isBST(root, NULL, NULL)){
        cout<<"Valid BST"<<"\n";
    }else{
        cout<<"Inalid BST"<<"\n";
    }
}