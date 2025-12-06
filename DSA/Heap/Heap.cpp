#include<bits/stdc++.h>
using namespace std;

class Heap{
    vector<int>vec; //max-heap
    public:
    void Insert(int value){
        vec.push_back(value);

        int child = vec.size()-1; //child index
        int parent = (child -1 )/2; //parent Index

        while(parent>=0 && vec[child] > vec[parent]){   //O(log n)
            swap(vec[child], vec[parent]);
            child = parent;
            parent = (child-1)/2;
        }
    }

    void heapify(int i){
        if(i >= vec.size()) return;
        int left = 2*i + 1;
        int right = 2*i + 2;
        int maxIndx = i;
        if(left < vec.size() && vec[left] > vec[maxIndx]){
            maxIndx = left;
        }
         if(right < vec.size() && vec[right] > vec[maxIndx]){
            maxIndx = right;
        }
        if(maxIndx != i){
             swap(vec[i], vec[maxIndx]);
            heapify(maxIndx);
        }
    }

    void pop(){
        if(vec.empty()) return;
        swap(vec[0], vec[vec.size()-1]); //O(1)
        vec.pop_back(); // O(1)
        heapify(0); //O(logn)
    }

    int top(){
        return vec[0];  //O(1)
    }

    bool empty(){
        return vec.size()==0; //O(1)
    }

    void show(){
        for(auto &i : vec){
            cout<<i<<" ";
        }
        cout<<"\t";
    }
    
};


int main(){
    vector<int>x = {1, 5, 2, 8, 3, 9, 0};
    Heap h;
    for(auto i : x){
        h.Insert(i);
    }

    h.show();
    h.pop();
   h.show();
}


