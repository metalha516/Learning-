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
Node* insert(Node* root, int value){
    if(root == NULL){
        root = new Node(value);
        return root;
    }
    if(value > root->data){
        root->right = insert(root->right, value);
    }
    if(value < root->data){
        root->left = insert(root->left, value);
    }
    return root;
}
Node* build(vector<int>x){
    Node* root = NULL;
    for(auto i : x){
        root = insert(root, i);
    }
    return root;
}
void inOrder(Node * root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}


void Print_IN_RAnge(Node* root, int start, int end){
    if(root == NULL) return;
    if(start <= root->data && root->data <= end){
       
         Print_IN_RAnge(root->left, start, end);
          cout<<root->data<<" ";
         Print_IN_RAnge(root->right, start, end);
    }

    if(root->data < start){
        Print_IN_RAnge(root->right, start, end);
    }

    if(root->data > end){
       Print_IN_RAnge(root->left, start, end);
    }
}

void printpath(vector<int>path){
      cout<<endl<<"path : ";
      for(auto &i : path){
        cout<<i<<" ";
      }
      cout<<endl;
}

void pathHelper(Node*root, vector<int>&path){
    if(root == NULL){
        return;
    }
    path.push_back(root->data);
    if(root->left == NULL && root->right == NULL){
        printpath(path);
        path.pop_back();
        return;
    }
    pathHelper(root->left, path);
    pathHelper(root->right, path);

    path.pop_back();

}

void rootToPath(Node* root){
    vector<int>path;
    pathHelper(root, path);
}


void levelOrder(Node* root){
    if(root == NULL) return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int lensz = q.size();
        for(int i = 0; i<lensz; i++){
            Node* curr = q.front();
            cout<<curr->data<<" ";
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right); 
            q.pop();
        }
        cout<<endl;
    }
}


bool validateHelper(Node* root, Node* min, Node* max){
    if(root == NULL){
        return true;
    }
    if(min != NULL && root->data < min->data){
        return false;
    }
      if(max != NULL && root->data > max->data){
        return false;
    }
    return validateHelper(root->left, min, max) && validateHelper(root->right, min, max);

}



bool validTree(Node* root){
    return validateHelper(root, NULL, NULL);
}





int main(){
    vector<int>values = {1, 4, 2, 6, 2, 8, 14, 9};
    Node* root = build(values);
    // Print_IN_RAnge(root, 2, 10);
    rootToPath(root);
    levelOrder(root);
    cout<<endl<<validTree(root);
}