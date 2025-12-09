#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node* left;
    Node* right;
    Node(int value){
        this->value = value;
        left=right=NULL;
    }
};

Node* BuildTreeSorted(vector<int>arr, int start, int end){
     if(start > end) return NULL;     
     int mid = start + (end - start)/2;
     Node* curr = new Node(arr[mid]);
     curr->left = BuildTreeSorted(arr, start, mid-1);
     curr->right = BuildTreeSorted(arr, mid+1, end);
     return curr;
}


void levelOrder(Node* root){
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
         Node* curr = q.front();
         cout<<curr->value<<" ";
         q.pop();

         if(curr->left!=NULL){
            q.push(curr->left);
         }if(curr->right != NULL){
            q.push(curr->right);
         }
    }
      
}



int main(){
    vector<int>arr = {1, 2, 3,4 ,5, 6, 7, 8, 9};
    Node* root = BuildTreeSorted(arr, 0, arr.size()-1);
    levelOrder(root);
}