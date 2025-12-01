#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr, int start, int end){
       int i = start-1;
       int pivot = arr[end];
       for(int j = start; j<end; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
       }
       i++;
       swap(arr[i], arr[end]);
       return i;
}


void quickSort(vector<int>&arr, int start, int end){
    if(start >= end){
          return;
    }
    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot-1);
    quickSort(arr, pivot+1, end);
}

void printArr(vector<int>&x){
    for(auto &it : x) cout<<it<<" ";
}

int main(){
    vector<int>x = {1, 6, 2, 9, 5, 3, 4, 8, 7};
    quickSort(x, 0, x.size()-1);
    printArr(x);
}