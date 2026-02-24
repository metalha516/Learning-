#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>A = {1, 2, 4, 5};
    vector<int>B = {1,8,3,9};

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans = 0;
    for(int i = 0; i<A.size(); i++){
        ans+=abs(A[i] - B[i]);
    }

    cout<<ans;
}