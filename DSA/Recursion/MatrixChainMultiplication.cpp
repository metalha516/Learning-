#include<bits/stdc++.h>
using namespace std;

int mcmrec(vector<int>arr, int i , int j){
    if(i == j) return 0;
    int ans = INT_MAX;
    for(int k = i; k<j; k++){
        int cost_1 = mcmrec(arr, i, k);
        int cost_2 = mcmrec(arr, k+1, j);
        int currentCost = cost_1+cost_2+(arr[i-1]*arr[k]*arr[j]);
        ans = min(ans, currentCost);
    }
    return ans;
}

int main(){
    vector<int>arr = {1, 2, 3, 4, 5};
    cout<<mcmrec(arr, 1, arr.size()-1);
}