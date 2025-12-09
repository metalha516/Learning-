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
    return -1;
}

Node* BuildpostNIn(vector<int>&inorder, vector<int>postorder, int &postindx, int left, int right){
    if(left > right) return NULL;
    Node* root = new Node(postorder[postindx--]);
    int inIndx = search(inorder, root->data);
    
    root->right = BuildpostNIn(inorder, postorder, postindx, inIndx+1, right);
    root->left = BuildpostNIn(inorder, postorder, postindx, left, inIndx-1);
    return root;
}

int main(){
    vector<int>postorder = {4, 5, 2, 3, 1};
    vector<int>inorder = {4, 2, 5, 1, 3};
    int postin = postorder.size()-1;
    Node* root = BuildpostNIn(inorder, postorder, postin, 0, inorder.size()-1);
    levelOrder(root);
}