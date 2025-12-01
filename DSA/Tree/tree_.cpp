#include<bits/stdc++.h>
using namespace std;
struct Node{
   int data;
   Node* left; 
   Node* right;
};

Node* CreateNode(int data){
    Node* curr = new Node();
    curr->data = data;
    curr->left = curr->right = nullptr;
    return curr;
}

void preOrder(Node* root){
    if(root == nullptr) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void levelOrder(Node* root){
    if(root == nullptr) return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int lensz = q.size();
        for(int i = 0; i<lensz; i++){
            Node* curr = q.front();
            cout<<curr->data<<" ";
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right); 
            q.pop();
        }
        cout<<endl;
    }
}


int height(Node* root){
    if(root == nullptr) return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right)+1;
}


int count(Node* root){
    if(root == nullptr) return 0;
    int left = count(root->left);
    int right= count(root->right);
    return left+right+1;
}

int sum(Node* root){
    if(root == nullptr) return 0;
    int left = sum(root->left);
    int right = sum(root->right);
    return left+right+root->data;
}

int main(){
    Node* root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    root->left->right = CreateNode(5);
    root->right->left = CreateNode(6);
    root->right->right = CreateNode(7);

    levelOrder(root);
    cout<<height(root)<<endl;
    cout<<count(root)<<endl;
    cout<<sum(root)<<endl;
}
