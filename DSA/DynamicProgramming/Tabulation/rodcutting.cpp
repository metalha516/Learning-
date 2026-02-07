#include <bits/stdc++.h>
using namespace std;

int rodcutting(vector<int> price, vector<int> length, int rodlen) {
    int n = length.size();
    vector<vector<int>> dp(n + 1, vector<int>(rodlen + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= rodlen; j++) {
            if (length[i - 1] <= j) {
                dp[i][j] = max(
                    price[i - 1] + dp[i][j - length[i - 1]],
                    dp[i - 1][j]
                );
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][rodlen];
}

int main() {
    vector<int> price = {1,5,8,9,10,17,17,20};
    vector<int> length = {1,2,3,4,5,6,7,8};
    int rodlen = 8;

    cout << rodcutting(price, length, rodlen);
    return 0;
}
