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


void levelOrder(Node* root){
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


int search(vector<int>arr, int k){
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] == k){
            return i;
        }
    }
}

Node* BuildPreNIn(vector<int>&inorder, vector<int>preorder, int &preindx, int left, int right){
    if(left > right) return NULL;
    Node* root = new Node(preorder[preindx++]);
    int inIndx = search(inorder, root->data);
    root->left = BuildPreNIn(inorder, preorder, preindx, left, inIndx-1);
    root->right = BuildPreNIn(inorder, preorder, preindx, inIndx+1, right);
    return root;
}

int main(){
    vector<int>preorder = {1, 2, 4, 5, 3};
    vector<int>inorder = {4, 2, 5, 1, 3};
    int prein = 0;
    Node* root = BuildPreNIn(inorder, preorder, prein, 0, inorder.size()-1);
    levelOrder(root);
}