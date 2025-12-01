// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int sum(int n){
    if(n==1) return 1;
    return n + sum(n-1);
}

bool is_sorted(vector<int>x, int i){
    if(i == x.size()-1) return true;
    if(x[i] > x[i+1]) return false;
    return is_sorted(x, i+1);
}

int first_occurance(vector<int>arr, int i, int target){
    if(i == arr.size()) return -1;
    if(arr[i] == target) return i;
    return first_occurance(arr, i+1, target);
}

int last_occurance(vector<int>arr, int i, int target){
    if(i == arr.size()) return -1;
    int indx = last_occurance(arr, i+1, target);
    if(indx == -1 && arr[i] == target) return i;
    return indx;
}

int power(int x, int n){
    if(n==0) return 1;
    int halfPower = power(x, n/2);
    int halfpowersqr = halfPower * halfPower;
    if(n&1) {return x*halfpowersqr;}
    return halfpowersqr;
}

int main() {
    // vector<int> x = {1, 2, 4, 4, 4, 6, 7};
    // cout<<last_occurance(x, 0, 4);
    cout<<power(3, 3);
    return 0;
}