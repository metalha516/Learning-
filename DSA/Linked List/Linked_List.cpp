#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }  
    ~Node(){
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

class List{
   public:
   Node*head;
   Node* tail;
   List(){
    head = tail = NULL;
   }
   ~List(){
     if(head != NULL){
        delete head;
        head = NULL;
     }
   }
   void push_front(int value){
    Node* newNode = new Node(value); 
    if(head == NULL){
        head=tail=newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
   }
   void push_back(int value){
        Node* newNode = new Node(value);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
   }
   void insert(int value, int pos){
    Node*temp = head;
    Node* newNode = new Node(value);
    for(int i = 0; i<pos-1; i++){
        temp = temp->next;
        if(temp == NULL){
            cout<<"Invalid";
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
   }
   void print(){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
   }
    void pop_front(){
        if(head == NULL) {cout<<"Link list is empty";return;}
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
    }
    void pop_back(){
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
    }
    int search_iterative(int value){
        Node* temp = head;
        int indx = 0;
        while(temp != NULL){
            if(temp->data == value){
                return indx;
            }
            temp= temp->next;
            indx++;
        }
        return -1;
    }
    void reverse(){
        Node* curr = head;
        Node* prev = NULL;
        while(curr!=NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    int getSize(){
        Node*temp = head;
        int size = 0;
        while(temp!=NULL){
            temp= temp->next;
            size++;
        }
        return size;
    }


    void FindnDelete(int n){
         int size = getSize();
         Node* temp = head;
         for(int i = 1; i<size-n; i++){
            temp = temp->next;
         }
         
         temp->next = temp->next->next;
    }

    bool isCycle(){
        Node* slow = head;
        Node* fast = head;
        while(fast!= NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }
        return false;
    }

    void removeCycle(){
        Node* slow = head;
        Node* fast = head;
        bool Cycle;
        while(fast!= NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {Cycle = true; break;};
        }
        if(!Cycle) return;
        slow = head;
        if(slow == fast){
            while(fast->next != slow){
                fast= fast->next;
            }
            fast->next = NULL;
        }else{
            Node* prev = fast;
            while(slow!= fast){
                slow = slow->next;
                prev = fast;
                fast = fast->next;
            }
            prev->next = NULL;
        }
    }
    
   Node* SplitAtMid(Node* head){    //// FIXED LINE (added parameter)
          Node * slow = head;
          Node* fast = head;
          Node* prev = NULL;
          while(fast!=NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
          }
          if(prev!= NULL){
             prev->next = NULL;
          }
          return slow;
    }

   Node* Merge(Node* left, Node* right){
    if(!left) return right;
    if(!right) return left;

    Node* res;

    if(left->data <= right->data){
        res = left;
        res->next = Merge(left->next, right);
    } else {
        res = right;
        res->next = Merge(left, right->next);
    }
    return res;
}


    Node* mergeSort(Node* head){
        if(head == NULL || head->next == NULL){
            return head;            //// FIXED LINE (previously returned NULL)
        }

        Node* rightHead = SplitAtMid(head);  //// FIXED LINE

        Node* left = mergeSort(head);
        Node *right = mergeSort(rightHead);

        return Merge(left, right);  //// FIXED LINE (previously Merge(head, rightHead))
    }

};

int main(){
    List ll;
    int size;
    cin>>size;
    while(size--){
        int x;
        cin>>x;
        ll.push_back(x);
    }
    // ll.reverse();
    // ll.FindnDelete(3);
    // cout<<ll.isCycle()<<endl;
    ll.head = ll.mergeSort(ll.head);
    ll.print();
}