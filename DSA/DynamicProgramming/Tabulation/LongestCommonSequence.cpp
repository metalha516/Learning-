#include<bits/stdc++.h>
using namespace std;

int longestCommonSequence(string s1, string s2){
     int n = s1.size(), m = s2.size();
   vector<vector<int>>dp = vector<vector<int>>(n+1, vector<int>(m+1, 0));
  
   for(int i = 1; i<n+1; i++){
    for(int j = 1; j<m+1; j++){
        if(s1[i-1] == s2[j-1]){
            dp[i][j] = 1 + dp[i-1][j-1];
        }else{
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
   }
   return dp[n][m];
}

int main(){
    string s1 = "iloveuniversityorbaust", s2 = "universityisbaust";
    vector<vector<int>>dp = vector<vector<int>>(s1.size()+1, vector<int>(s2.size()+1, -1));
    cout<<longestCommonSequence(s1, s2);
}
