#include<bits/stdc++.h>
using namespace std;

bool knapsack(vector<int>&value, vector<int>&wt, int W, int n, vector<vector<int>>&dp){
    if(W == 0) return true;  // Found exact sum
    if(n == 0) return false; // No items left but W > 0
    
    if(dp[n][W] != -1) return dp[n][W];

    int itemval = value[n-1];
    int itemwt = wt[n-1];

    bool result = false;
    if(itemwt <= W){
        //include
        bool ans1 = knapsack(value, wt, W-itemwt, n-1, dp);
        //exclude
        bool ans2 = knapsack(value, wt, W, n-1, dp);

        result = ans1 || ans2;
    }else{
        //exclude
        result = knapsack(value, wt, W, n-1, dp);
    }
    
    return dp[n][W] = result;
}

int main(){
    vector<int>numbers = {4, 2, 7, 1, 3};
    
    int target = 10, n = numbers.size();
    vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
    cout<<knapsack(numbers, numbers, target, n, dp);
}