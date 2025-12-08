#include<bits/stdc++.h>
using namespace std;


int count_Dsit(vector<int>x){
     unordered_set<int>s;

     for(auto &i : x){
        s.insert(i);
     
    }
    return s.size();
}






int main(){
    cout<<count_Dsit({1, 3, 4, 4, 5, 2, 7, 8});
}