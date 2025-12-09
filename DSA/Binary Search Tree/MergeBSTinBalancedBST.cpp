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

Node* givenTree(){
    Node* curr = new Node(2);
    curr->left = new Node(1);
    curr->right = new Node(4);
    return curr;
}

Node* givenTree_2(){
    Node* curr = new Node(9);
    curr->left = new Node(3);
    curr->right = new Node(14);
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

Node* MergeBST(Node*root_1, Node*root_2){
    vector<int>node_1;
    vector<int>node_2;
    vector<int>merge;

    inorder(node_1, root_1);
    inorder(node_2, root_2);

    int i = 0, j = 0;

    while(i<node_1.size() && j<node_2.size()){
        if(node_1[i] < node_2[j]){
            merge.push_back(node_1[i++]);
        }else{
            merge.push_back(node_2[j++]);
        }
    }
    
    while(i<node_1.size()){
        merge.push_back(node_1[i++]);
    }
    while(j<node_2.size()){
        merge.push_back(node_2[j++]);
    }
    return BuildTreeSorted(merge, 0, merge.size()-1);
}


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


int main(){
    Node* main_root = MergeBST(givenTree(), givenTree_2());
    levelOrder(main_root);
}


