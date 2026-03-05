#include<bits/stdc++.h>
using namespace std;

int MooreVoting(vector<int>&arr){
    int freq = 0, ans = 0;
    for (int i : arr){
        if(freq == 0) ans = i;
        if(ans == i) freq++;
        else freq--;
    }

    freq = 0;
    for(int num : arr){
        if(num == ans)
            freq++;
    }

    return (freq > arr.size()/2) ? ans : -1;
}


int main(){
    vector<int>arr = {1, 3, 3, 3, 3, 5, 3, 8, 4, 3};
    cout<<MooreVoting(arr);
}