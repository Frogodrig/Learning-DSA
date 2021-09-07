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

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcPointers(Node* root, Node** first, Node** mid, Node** last, Node** prev){

    if(root == NULL){
        return;
    }
    //will make recursive calls in inorder fashion
    calcPointers(root->left, first, mid, last, prev);

    if(*prev && (root->data) < (*prev)->data) { //prev will be present as long as it's not the smallest element in the BST
        if(!(*first)){ //If first is NULL it means that it is the first violation in BST
            *first = *prev; // discussed this in case 1 refer ur notes
            *mid = root;
        }
        else{
            *last = root; //If first isn't null it means its a second violation of the BST
        }
    }
    *prev = root; // this is simply setting the current node as prev as we are moving onto the next number in the sequence
    calcPointers(root->right, first, mid, last, prev);
}


void restoreBST(Node* root){

    Node* first, *mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    calcPointers(root, &first, &mid, &last, &prev);

    if(first && last){ // 2nd case, refer to notes (not adjacent violation)
        swap(&(first->data), &(last->data));
    }

    else if(first && mid){ //1st case refer to notes (adjacent violation)
        swap(&(first->data), &(mid->data));
    }
}

void inorder(Node* root){

    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){

    Node* root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);

    inorder(root);
    cout<<"\n";
    restoreBST(root);

    inorder(root);
    cout<<"\n";
    return 0;
}

/*Alternate LeetCode solution*/

// class Solution {

//     TreeNode* first=NULL;

//     TreeNode* second=NULL;

//     TreeNode* prev = new TreeNode(INT_MIN);

// public:

//     void recoverTree(TreeNode* root) {

//         help(root);

//         swap(first->val, second->val);

//     }

    

//     void help(TreeNode* root){

//         if(root==NULL)  return;

//         help(root->left);

//         if(first==NULL && prev->val >= root->val)   first=prev;

//         if(first!=NULL && prev->val >= root->val)   second=root;

//         prev=root;

//         help(root->right);

//     }

// };