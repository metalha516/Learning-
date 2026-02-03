#include<bits/stdc++.h>
using namespace std;

void printPermutation(string str, string ans){
    int n = str.size();
    if(n==0){
        cout<<ans<<endl;
        return;
    }
    for(int i = 0; i<str.size(); i++){
        char ch = str[i];
        string newString = str.substr(0, i) + str.substr(i+1, n-i-1); // remove ith character from string
        printPermutation(newString, ans+ch); //join ith character to answer
    }
}

int main(){
    string str = "abc", ans = "";
    printPermutation(str, ans);
}