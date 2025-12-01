#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr, int start, int mid, int end){
    vector<int>temp;
    int i = start, j = mid+1;
    while(i<= mid && j<=end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=end){
        temp.push_back(arr[j++]);
    }

    for(int idx = start, x = 0; idx<=end; idx++){
        arr[idx] = temp[x++];
    }
}

void mergeSort(vector<int>&arr, int start, int end){
    if(start >= end) return;
    int mid = start + (end-start)/2;
    
    mergeSort(arr, start, mid); //Left Subarray
    mergeSort(arr, mid+1, end); //Right Subarray

    merge(arr, start, mid, end);
}

void print_Array(vector<int>&x){
    for(auto &i : x){
        cout<<i<<" ";
    }
}

int main(){
    vector<int> arr = {3, 6, 1, 4, 2, 9};
    mergeSort(arr, 0, arr.size()-1);
    print_Array(arr);
}