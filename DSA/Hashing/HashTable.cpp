#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    string key;
    int val;
    Node* next;
    Node(string key, int val){
        this->key = key;
        this->val = val;
        this->next = NULL;
    }

    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

class HashTable{
    int totalSize;
    int currentSize;
    Node** table;

    int hashFunction(string key){
        int idx = 0;
        for(int i = 0; i<key.size(); i++){
            idx += (key[i] * key[i])%totalSize;
        }
        return idx%totalSize;
    }

    void rehash(){
        Node** oldTable = table;
        int oldSize = totalSize;

        totalSize*=2;
        currentSize = 0;
        table = new Node*[totalSize];
        
        for(int i = 0; i<totalSize; i++){
            table[i] = NULL;
        }

        for(int i = 0; i<oldSize; i++){
            Node* temp = oldTable[i];
            while(temp != NULL){
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }

    public:
    HashTable(int size){
        totalSize = size;
        currentSize = 0;
        table = new Node*[size];
        
        for(int i = 0; i<totalSize; i++){
            table[i] = NULL;
        }
    }

    void insert(string key, int val){
        int idx = hashFunction(key);

        Node* newNode = new Node(key, val);
        
        newNode->next = table[idx];
        table[idx] = newNode;

        currentSize++;
        double lambda = currentSize / (double) totalSize;
        if(lambda > 1){
            rehash();
        }
    }

    bool exist(string key){
         int indx = hashFunction(key);
         Node* temp = table[indx];

         while (temp!=NULL)
         {
            if(temp->key == key){
                return true;
            }
            temp = temp->next;
         }
         
         return false;
    }

    int search(string key){
        int indx = hashFunction(key);
        Node*temp = table[indx];
        while(temp!=NULL){
            if(temp->key == key){
                return temp->val;
            }
            temp = temp->next;
        }
        return -1;
    }

    void erase(string key){
        int indx = hashFunction(key);
        Node*temp  = table[indx];
        Node*prev = temp;
        while(temp!=NULL){
            if(temp->key == key){
                if(prev == temp){
                    table[indx] = temp->next;
                }else{
                    prev->next = temp->next;
                }
            }
            prev = temp;
            temp = temp->next;
        }
    }

    void print(){
        for(int i = 0; i<totalSize; i++){
             Node* temp = table[i];
             cout<<"index : "<<i<<" ";
             while(temp != NULL){
                cout<<"<"<<temp->key<<" ~ "<<temp->val <<" >, ";
                temp = temp->next;
             }
             cout<<endl;
        }
    }
};


int main(){
    HashTable ht(10);

     ht.insert("talha", 677);
       ht.insert("sorme", 6907);
          ht.insert("tamim", 675);
             ht.insert("Rifat", 647);
                ht.insert("Mahim", 477);
                   ht.insert("Nabil", 977);
                      ht.insert("Arafat", 1077);
                      ht.insert("Lubnan", 1277);
                      ht.insert("Manha", 9077);
    
                      ht.print();
                      ht.erase("Manha");
                      ht.print();
}