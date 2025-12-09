#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

class Info{
    public:
    bool isBST;
    int Max;
    int Min;
    int size;
    Info(bool isBST, int Max, int Min, int size){
        this->isBST = isBST;
        this->Max = Max;
        this->Min = Min;
        this->size = size;
    }
};

int maxSize;
Info* largestBST(Node* root){
    if(root == NULL){
        return new Info(true, INT_MIN, INT_MAX, 0);
    }
    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);
    int currMax =max(root->data, max(leftInfo->Max, rightInfo->Max));
    int currMin = min(root->data, min(leftInfo->Min, rightInfo->Min));
    int currSize = leftInfo->size + rightInfo->size + 1;
    if(leftInfo->isBST && rightInfo->isBST && root->data > leftInfo->Max && root->data < rightInfo->Min){
        maxSize = max(maxSize, currSize);
        return new Info(true, currMax, currMin, currSize);
    }
     return new Info(false, currMax, currMin, currSize);
}



Node* givenBT(){
     Node* curr = new Node(50);
     curr->left = new Node(30);
     curr->right = new Node(60);

     curr->left->left = new Node(5);
     curr->left->right = new Node(20);

     curr->right->left = new Node(45);
     curr->right->right = new Node(70);

     curr->right->right->left = new Node(65);
     curr->right->right->right = new Node(80);

     return curr;
}


int main(){
    Node * root = givenBT();
    Info* details = largestBST(root);
    cout<<maxSize;
}