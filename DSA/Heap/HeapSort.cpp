#include<bits/stdc++.h>
using namespace std;
void heapify(int i, vector<int>&arr, int n){
      if(i >= n) return;
      int left = 2*i +1;
      int right = 2*i + 2;
      int maxIndx = i;

      if(left < n && arr[left] > arr[maxIndx]){
        maxIndx = left;
      }
      if(right < n && arr[right] > arr[maxIndx]){
        maxIndx = right;
      }
      if(maxIndx != i){
        swap(arr[i], arr[maxIndx]);
        heapify(maxIndx, arr, n);
      }
}
void heapSort(vector<int>&arr, int n){
     for(int i = n/2-1; i>=0; i--){
        heapify(i, arr, n);
     }

     for(int i = n-1; i>=0; i--){
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
     }
}
int main(){
    vector<int> a = {1, 4, 2, 9, 5, 3, 12, 10, 17, 14, 20, 19, 29, 25, 50};
    heapSort(a, a.size());
    for(auto i : a){
        cout<<i<<" ";
    }
}
