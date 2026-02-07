#include<bits/stdc++.h>
using namespace std;

int longestCommonSequence(string s1, string s2){
    if(s1.size()==0 || s2.size()==0) return 0;

    int n = s1.size();
    int m = s2.size();

    if(s1[n-1] == s2[m-1]){
        return 1 + longestCommonSequence(s1.substr(0, n-1), s2.substr(0, m-1));
    }else{
        int ans1 = longestCommonSequence(s1.substr(0, n-1), s2);
        int ans2 = longestCommonSequence(s1, s2.substr(0, m-1));
        return max(ans1, ans2);
    }
    
}

int main(){
    string s1 = "iloveuniversityorbaust", s2 = "universityisbaust";

    cout<<longestCommonSequence(s1, s2);
}
