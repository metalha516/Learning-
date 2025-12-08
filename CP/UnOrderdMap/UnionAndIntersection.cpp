#include<bits/stdc++.h>
using namespace std;


void printUnion(vector<int>a, vector<int>b){
    unordered_set<int>s;
    for(auto i : a){
        s.insert(i);
    }
    for(auto i : b){
        s.insert(i);
    }

    for(auto el : s){
        cout<<el<<" ";
    }
}


void printIntersection(vector<int>a, vector<int>b){
    unordered_set<int>s;
    for(auto el : a){
        s.insert(el);
    }

    for(auto el : b){
        if(s.find(el) != s.end()){
            cout<<el<<" ";
        }
    }
}

int main(){
    vector<int> a = {1, 2, 3, 4};
    vector<int>b = {2, 3, 4, 5, 6, 7};
    printIntersection(a, b);
}