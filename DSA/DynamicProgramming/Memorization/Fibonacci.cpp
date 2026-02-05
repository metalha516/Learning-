#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n, vector<int>&fibo){
    if(n == 0 || n==1) return n;
    if(fibo[n] != -1) return fibo[n];
    fibo[n] = fibonacci(n-1, fibo) + fibonacci(n-2, fibo);
    return fibo[n];
}


int main(){
    int n = 6;
    vector<int>dp(n+1, -1);
    cout<<fibonacci(n, dp);
}