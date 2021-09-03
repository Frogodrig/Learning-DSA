#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node(int val){
        data = val;
    }
};


Node* insertBST(Node* root, int val){

    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insertBST(root->left, val);
    } else{
        root->right = insertBST(root->right, val);
    }
    
    return root;
}

Node* searchInBST(Node* root, int key){

    if(root == NULL){
        return NULL;
    }

    if(root->data == key){
        return root;
    }

    if(root->data > key){
        return searchInBST(root->left, key);
    }

    return searchInBST(root->right, key);
}

void inorder(Node* root){

    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* inorderSucc(Node* root){
    Node* curr = root;
    while(curr && curr->left!=NULL){
        curr = curr->left;  //we check curr->left because we want a node less than the current node to maintain BST
    }
    return curr;
}

Node* deleteInBST(Node* root, int key){

    if(key < root->data){
        root->left = deleteInBST(root->left, key);
    }
    else if(key > root->data){
        root->right = deleteInBST(root->right, key);
    }

    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}

int main(){

    Node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 6);

    if(searchInBST(root, 5) == NULL){
        cout<<"Key doesn't exist"<<"\n";
    }else{
        cout<<"Key exists"<<"\n";
    }

    inorder(root);
    cout<<endl;
    root = deleteInBST(root, 3);
    inorder(root);
    cout<<endl;
    return 0;
}