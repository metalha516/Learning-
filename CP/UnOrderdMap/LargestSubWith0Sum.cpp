#include<bits/stdc++.h>
using namespace std;

int largetSub(vector<int>arr){
    unordered_map<int, int> map;
    int sum = 0;
    int ans = 0;
    for(int j = 0; j<arr.size(); j++){
        sum+=arr[j];
        if(map.count(sum)){
             int curLen = j - map[sum];
             ans = max(ans, curLen);
        }else{
             map[sum] = j;
        }
    }
    return ans;
}


int main(){
    vector<int>arr = {15, -2, 3, -8, 5, 1 ,7, 10};
    cout<<largetSub(arr);
}