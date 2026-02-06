#include<bits/stdc++.h>
using namespace std;
//plain recursion 

bool knapsack(vector<int>&nums,int W){
   int n =  nums.size();
    vector<vector<int>>dp(n+1, vector<int>(W+1, 0));
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=W; j++){

            if(nums[i-1] <= j){
                dp[i][j] = max(nums[i-1]+dp[i-1][j-nums[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W] == W;
}

int main(){
    vector<int>nums = {4, 2,7,1,3};
    
    int W = 10;
    
    cout<<knapsack(nums,W);
}