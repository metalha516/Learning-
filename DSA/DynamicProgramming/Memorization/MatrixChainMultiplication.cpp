#include<bits/stdc++.h>
using namespace std;

int mcmrec(vector<int>arr, int i , int j, vector<vector<int>>&dp){
    if(i == j) return 0;
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k = i; k<j; k++){
        int cost_1 = mcmrec(arr, i, k, dp);
        int cost_2 = mcmrec(arr, k+1, j, dp);
        int currentCost = cost_1+cost_2+(arr[i-1]*arr[k]*arr[j]);
        ans = min(ans, currentCost);
    }
    return dp[i][j] = ans;
}

int main(){
    vector<int>arr = {1, 2, 3, 4, 3};
    vector<vector<int>>dp(arr.size()+1, vector<int>(arr.size()+1, -1));
    cout<<mcmrec(arr, 1, arr.size()-1, dp);
}