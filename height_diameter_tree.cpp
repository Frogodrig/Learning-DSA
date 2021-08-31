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

int heightOfTree(Node* root){

    if(root == NULL){
        return 0;
    }

    int lHeight = heightOfTree(root->left);
    int rHeight = heightOfTree(root->right);

    return max(lHeight, rHeight) + 1;
}

int calcheightOfTree(Node* root){

    if(root == NULL){
        return 0;
    }
    return max(calcheightOfTree(root->left), calcheightOfTree(root->right)) + 1;
}

int diameterOftree(Node* root){

    if(root == NULL){
        return 0;
    }

    int lHeight = calcheightOfTree(root->left);
    int rHeight = calcheightOfTree(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = diameterOftree(root->left);
    int rDiameter = diameterOftree(root->right);

    return max(currDiameter, max(lDiameter,rDiameter));
}

int calcDiameter(Node* root, int* height){

    if(root == NULL){
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDiameter = calcDiameter(root->left,&lh);
    int rDiameter = calcDiameter(root->right,&rh);

    int currDiameter = lh+rh+1;
    *height = max(lh,rh) + 1;

    return max(currDiameter,max(lDiameter,rDiameter));
}


int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    cout<<heightOfTree(root)<<endl;
    cout<<diameterOftree(root)<<endl;

    int height = 0;
    cout<<calcDiameter(root,&height)<<endl;
    return 0;
}