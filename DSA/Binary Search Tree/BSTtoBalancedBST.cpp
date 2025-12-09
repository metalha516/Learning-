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

Node* givenBST(){
     Node* curr = new Node(6);
     curr->left = new Node(5);
     curr->left->left = new Node(4);
     curr->left->left->left = new Node(3);
     curr->right = new Node(7);
     curr->right->right = new Node(8);
     curr->right->right->right = new Node(9);
     return curr;
}

void inorder(vector<int>&inseq, Node* root){
    if(root == NULL) return;
    inorder(inseq, root->left);
    inseq.push_back(root->data);
    inorder(inseq, root->right);
}

Node* BuildTreeSorted(vector<int>arr, int start, int end){
     if(start > end) return NULL;     
     int mid = start + (end - start)/2;
     Node* curr = new Node(arr[mid]);
     curr->left = BuildTreeSorted(arr, start, mid-1);
     curr->right = BuildTreeSorted(arr, mid+1, end);
     return curr;
}


void levelOrder(Node*root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        cout<<curr->data<<" ";
        q.pop();
        if(curr->left!=NULL){
            q.push(curr->left);
        }if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}


Node* balanced_BST(Node* root){
    vector<int>nodes;
    inorder(nodes, root);
    Node * newRoot = BuildTreeSorted(nodes, 0, nodes.size()-1);
    return newRoot; 
}



int main(){
    Node* root = givenBST();
    Node* balbst = balanced_BST(root);
    levelOrder(balbst);
}

