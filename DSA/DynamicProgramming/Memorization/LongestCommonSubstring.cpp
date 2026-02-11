#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, string &s1, string &s2,
          vector<vector<int>> &dp, int &ans) {

    if(i == 0 || j == 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i-1] == s2[j-1]) {
        dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp, ans);
        ans = max(ans, dp[i][j]);
    } else {
        dp[i][j] = 0;
    }

    // explore other endings
    solve(i-1, j, s1, s2, dp, ans);
    solve(i, j-1, s1, s2, dp, ans);

    return dp[i][j];
}

int main() {
    string s1 = "abcde", s2 = "abgce";
    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    int ans = 0;

    solve(n, m, s1, s2, dp, ans);
    cout << ans;
}
