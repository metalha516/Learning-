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


bool search(Node* root, int val){
    if(root == NULL){
        return false;
    }


    if(root->data == val){}
    return true;

    if(root->data > val){
        return search(root->right, val);
    }else{
        return search(root->left, val);
    }
    return false;
}



Node* insert(Node* root, int data){
     if(root == NULL){
        root = new Node(data);
        return root;
     }
     if(data > root->data){
        root->right = insert(root->right, data);
     }else if(data < root->data){
        root->left = insert(root->left, data);
     }
     return root;
}


Node* buildTree(vector<int>value){
    Node* root = NULL;
    for(auto i : value){
        root = insert(root, i);
    }
    return root;
}


void inOrder(Node* root){
    if(root == NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}


//delete node algorithm 

Node* getInorderSuccessor(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}



Node* delNode(Node* root, int val){
    if (root == NULL) return NULL;

    if(val < root->data){
        root->left = delNode(root->left, val); 
    }else if(val > root->data){
        root->right = delNode(root->right, val);
    }else{
        if(root->left == NULL && root->right == NULL){ //for NO child
            delete root; 
            return NULL;
        }

        if(root->left == NULL || root->right == NULL){  //For one child
            return root->left == NULL ? root->right : root->left;
        }

        Node* IS = getInorderSuccessor(root->right);  //for 2 child
        root->data = IS->data;
        root->right = delNode(root->right, IS->data);
        return root;
    }
}

void preOrder(Node* root){
    if (root == NULL ){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}






int main(){
     vector<int>values = {5, 7, 10, 20, 15, 25, 30, 40, 50};
     Node* root = buildTree(values);
     for(auto i : values){
        root = insert(root, i);
     }
     preOrder(root);
     cout<<endl;
     root = delNode(root, 15);
     preOrder(root);
}