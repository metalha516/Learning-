#include<bits/stdc++.h>
using namespace std;


void majorityElement(vector<int>arr){
    unordered_map<int, int>freq;

    for(int i = 0;i<arr.size(); i++){
        if(freq.count(arr[i])){
            freq[arr[i]]++;
        }else{
            freq[arr[i]] =1;
        }
    }

    for(pair<int, int> p : freq){
        if(p.second > arr.size()/3){
            cout<<p.first<<" ";
        }
    }
    cout<<endl;
}


int main(){
    majorityElement({1, 1, 1, 5});
}