#include<bits/stdc++.h>
using namespace std;

int longestCommonSequence(string s1, string s2, vector<vector<int>>&dp){
    if(s1.size()==0 || s2.size()==0) return 0;
    
    int n = s1.size();
    int m = s2.size();
    
    if(dp[n][m] != -1){
        return dp[n][m];
    }

    if(s1[n-1] == s2[m-1]){
        dp[n][m] = 1 + longestCommonSequence(s1.substr(0, n-1), s2.substr(0, m-1), dp);
    }else{
        int ans1 = longestCommonSequence(s1.substr(0, n-1), s2, dp);
        int ans2 = longestCommonSequence(s1, s2.substr(0, m-1), dp);
        dp[n][m] = max(ans1, ans2);
    }
    return dp[n][m];
}

int main(){
    string s1 = "iloveuniversityorbaust", s2 = "universityisbaust";
    vector<vector<int>>dp = vector<vector<int>>(s1.size()+1, vector<int>(s2.size()+1, -1));
    cout<<longestCommonSequence(s1, s2, dp);
}
