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
};

class Queue{
    public:
    Node* head; 
    Node* tail;
    Queue(){
    head = tail = NULL;
    }
    void push(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int front(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return head->data;
    }
    
    bool isEmpty(){
        return head == NULL;
    }
};

int main(){
    Queue q;
    q.push(2);
    q.push(5); q.push(9); q.push(8); q.push(11);
    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}