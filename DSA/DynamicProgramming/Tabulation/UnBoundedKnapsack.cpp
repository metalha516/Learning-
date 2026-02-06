#include<bits/stdc++.h>
using namespace std;
//plain recursion 

int knapsack(vector<int>&value, vector<int>&wt, int W, int n){
    vector<vector<int>>dp(n+1, vector<int>(W+1, 0));
    
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<W+1; j++){
            int itemwt = wt[i-1];
            int itemvalue = value[i-1];

            if(itemwt <= j){
                dp[i][j] = max(dp[i][j-itemwt]+itemvalue , dp[i-1][j]); //not i-1 here
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main(){
    vector<int>value = {10, 15, 30, 45, 50};
    vector<int>wt = {1, 2, 3, 3, 4};
    
    int W = 7, n = value.size();
    
    cout<<knapsack(value, wt, W, n);
}