#include<bits/stdc++.h>
using namespace std;
//plain recursion 

int knapsack(vector<int>&value, vector<int>&wt, int W, int n, vector<vector<int>>&dp){
    if(n == 0 || W == 0) return 0;
    
    if(dp[n][W] != -1) return dp[n][W];

    int itemval = value[n-1];
    int itemwt = wt[n-1];

    if(itemwt <= W){
        //include
        int ans1 = knapsack(value, wt, W-itemwt, n, dp) + itemval; //here n-1 is invalid
        //exclude
        int ans2 = knapsack(value, wt, W, n-1, dp);

        dp[n][W] = max(ans1, ans2);
    }else{
        //exclude
        dp[n][W] = knapsack(value, wt, W, n-1, dp);
    }
    return dp[n][W];
}

int main(){
    vector<int>value = {10, 15, 30, 45, 50};
    vector<int>wt = {1, 2, 3, 3, 4};
    
    int W = 7, n = value.size();
    vector<vector<int>>dp(n+1, vector<int>(W+1, -1));
    cout<<knapsack(value, wt, W, n, dp);
}