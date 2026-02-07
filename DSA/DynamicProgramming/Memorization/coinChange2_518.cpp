#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(int i, int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        if (i == n || amount < 0) return 0;

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        // take coin i (unlimited times)
        int take = solve(i, amount - coins[i], coins);

        // skip coin i
        int skip = solve(i + 1, amount, coins);

        dp[i][amount] = take + skip;

        return dp[i][amount];
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        dp.assign(n+1, vector<int>(amount+1, -1));
        return solve(0, amount, coins);
    }
};
