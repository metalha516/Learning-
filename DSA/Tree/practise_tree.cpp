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

//Diameter of a tree
int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int curr = height(root->left) + height(root->right) + 1;
    int left = diameter(root->left);
    int right = diameter(root->right);
    return max(curr, max(left, right));
}
//Diameter optimized
pair<int, int>diam_op(Node* root){
    if(root == NULL) return make_pair(0, 0);
    pair<int, int> leftInfo = diam_op(root->left);
    pair<int, int> rightInfo = diam_op(root->right);
    int currDim = leftInfo.second + rightInfo.second + 1;
    int finalDim = max(currDim, max(leftInfo.first, rightInfo.first));
    int finalheight = max(leftInfo.second, rightInfo.second);
    return make_pair(finalDim, finalheight);
}

bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL) return true;
    else if(root1 == NULL || root2 == NULL) return false;
    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

bool isSubtree(Node* root, Node* subRoot){
    if(root == NULL && subRoot == NULL) return true;
    else if(root == NULL || subRoot == NULL) return false;

    if(root->value == subRoot->value){
       if(isSubtree) return true;
    }

    bool LeftisSubtree = isSubtree(root->left, subRoot);
    if(!LeftisSubtree){
           return isSubtree(root->right, subRoot);
    }
    return true;
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

void kth_helper(Node * root, int k, int currlevel){
    if(root == NULL){
        return;
    }
    if(currlevel == k){
        cout<<root->value<<" ";
        return;
    }
    kth_helper(root->left, k, currlevel+1);
    kth_helper(root->right, k, currlevel+1);
}

void kth_level(Node* root, int k){
      kth_helper(root, k , 1);
      cout<<endl;
}

bool rootToNodePath(Node* root, int n, vector<int>&path){
    if(root == NULL)return false;

    path.push_back(root->value);
    
    if(root->value == n) return true;

    bool isLeft = rootToNodePath(root->left, n, path);
    bool isRight = rootToNodePath(root->right, n, path);

    if(isLeft || isRight) return true;

    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2){
    vector<int>path1; 
    vector<int>path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1;
    for(int i = 0, j = 0; i<path1.size() && j<path2.size(); i++,j++){
        if(path1[i] != path2[j]) return lca;
        lca = path1[i];
    }
    return lca;
}

Node* LCA_OP(Node* root, int n1, int n2){
    if(root == NULL) return NULL;
    if(root->value == n1 || root->value == n2){
             return root;
    }
    Node* leftLCA = LCA_OP(root->left, n1, n2);
    Node* rightLCA = LCA_OP(root->right, n1, n2);
    if(leftLCA != NULL && rightLCA != NULL) return root;
    return leftLCA == NULL ? rightLCA : leftLCA;
}


int dist(Node* root, int n){
    if(root == NULL) return -1;
    if(root->value == n) return 0;

    int left_dist = dist(root->left, n);
    if(left_dist != -1) return left_dist+1;

    int right_dist = dist(root->right, n);
    if(right_dist != -1) return right_dist+1;

    return -1;
}

int min_dist(Node* root, int n1, int n2){
    Node* lca = LCA_OP(root, n1, n2);
    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);
    return dist1+dist2;
}


int main(){
    vector<int>nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildtree(nodes);
    // levelOrder(root);
    // cout<<height(root)<<endl;
    // cout<<CountNode(root)<<endl;
    // cout<<sum(root)<<endl;
    int n1 = 3, n2 = 5;
    cout<<LCA_OP(root, n1, n2)->value;
    // kth_level(root, 3);
    return 0;
}