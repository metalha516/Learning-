#include<bits/stdc++.h>
using namespace std;
int kadhan(vector<int>&arr){
    int currSum = 0 ,maxSum = 0;
    for(int i : arr){
        currSum+=i;
        maxSum = max(currSum, maxSum);
        if(currSum < 0){
            currSum = 0;
        }
    }
    return maxSum;
}
int main(){
    vector<int>arr = {2, 7, 3, 9, 4, 10, 4, 6};
    cout<<"Maxium Subarray Sum : "<<kadhan(arr);
}