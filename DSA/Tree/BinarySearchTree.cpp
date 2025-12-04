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
static int idx = -1;

Node* buildtree(vector<int> nodes){
      idx++;
      if(nodes[idx] == -1)
      return NULL;     
      Node* currnode = new Node(nodes[idx]);
      currnode->left = buildtree(nodes);
      currnode->right = buildtree(nodes);
      return currnode;
}

void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->value<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
}

void postoder(Node* root){
    if(root == NULL) return;
    postoder(root->left);
    postoder(root->right);
    cout<<root->value<<" ";
}


void levelOrder(Node* root){
    queue<Node*>Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        Node*curr = Q.front();
        Q.pop();
        if(curr == NULL){
        cout<<endl;
        if(Q.empty()) break;
        Q.push(NULL); 
        }else{
           cout<<curr->value;
           if(curr->left != NULL){
            Q.push(curr->left);
           }if(curr->right != NULL){
            Q.push(curr->right);
           }
        }
    }
}

int height(Node * root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) +1;
}

int CountNode(Node *root){
    if(root == NULL){
        return 0;
    }
    int left = CountNode(root->left);
    int right = CountNode(root->right);
    return left+right+1;
}

int sum(Node *root){
    if(root == NULL){return 0;}
    int left = sum(root->left);
    int right = sum(root->right);
    return left+right+root->value;
}

int search(Node* root, int target){
    if(root == NULL) return -1;
    if(root->value == target) return root->value;
    if(root->left == NULL) return search(root->right, target);
    else
    return search(root->left, target);

}

int main(){
    vector<int>nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildtree(nodes);
    levelOrder(root);
    cout<<height(root)<<endl;
    cout<<CountNode(root)<<endl;
    cout<<sum(root)<<endl;
    cout<<search(root, 3);
}