#include<bits/stdc++.h>
using namespace std;

int cat(int n){

    if(n == 0 || n == 1) return 1;
    
    int ans = 0;

    for(int i = 0; i<n; i++){
        ans+=cat(i)*cat(n-i-1);
    }
    return ans;
}


int main(){
    cout<<cat(50);
}