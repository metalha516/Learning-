#include<bits/stdc++.h>
using namespace std;

void print(vector<int>&arr){
    for(int i : arr){
       cout<<i<<" ";
     }
}

void CountingSort(vector<int>&arr){
     int Max_val = 0;
     for(int i : arr){
        if(i > Max_val){
            Max_val = i;
        }
     }

     vector<int>count(Max_val+1, 0);

     for(int i = 0; i<arr.size(); i++){
        count[arr[i]]++;
     }

     for(int i = 1; i<=Max_val; i++){
        count[i]+=count[i-1];
     }
     vector<int>ans(arr.size());
     for(int i = arr.size()-1; i>=0; i--){
          ans[count[arr[i]]-1] = arr[i];
          count[arr[i]]--;
     }
     print(ans);
}

int main(){
    vector<int>arr = {5, 2, 8, 3, 9, 3, 1, 8, 6, 7};
    CountingSort(arr);
    cout<<"n";
}