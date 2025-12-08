#include<bits/stdc++.h>
using namespace std;

int SubarraySum(vector<int>arr, int k){
    unordered_map<int, int>map;
    map[0] = 1;
    int sum = 0;
    int ans = 0;
    for(int j = 0; j<arr.size(); j++){
        sum+=arr[j];
        if(map.count(sum-k)){
            ans+=map[sum-k];
        }
        if(map.count(sum)){
            map[sum]++;
        }else{
            map[sum] = 1;
        }
    }
    return ans;
}


int main(){
     vector<int> arr = {1, 2, 3, 4, -9, -30, 2, 5, 6};
     cout<<SubarraySum(arr, 5);
}