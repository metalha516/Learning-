#include<bits/stdc++.h>
using namespace std;

int fastExponential(int x, int n){
    int ans = 1;
    while(n > 0){
        int lstbit = n&1;
        if(lstbit){
            ans*=x;
        }
        x*=x;
        n= n>>1;
    }
    return ans;
}


int main(){
    cout<<fastExponential(2, 4);
}