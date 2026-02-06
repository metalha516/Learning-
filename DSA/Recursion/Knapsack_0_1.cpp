#include<bits/stdc++.h>
using namespace std;
//plain recursion 

int knapsack(vector<int>&value, vector<int>&wt, int W, int n){
    if(n == 0 || W == 0) return 0;

    int itemval = value[n-1];
    int itemwt = wt[n-1];

    if(itemwt <= W){
        //include
        int ans1 = knapsack(value, wt, W-itemwt, n-1) + itemval;
        //exclude
        int ans2 = knapsack(value, wt, W, n-1);

        return max(ans1, ans2);
    }else{
        //exclue
        return knapsack(value, wt, W, n-1);
    }
}




int main(){
    vector<int>value = {10, 15, 30, 45, 50};
    vector<int>wt = {1, 2, 3, 3, 4};
    int W = 7;
    cout<<knapsack(value, wt, W, value.size());
}