#include<bits/stdc++.h>
using namespace std;
int Binary_Search(vector<int>&arr, int start, int end, int target){
    if(start > end) return -1;
    int mid = start + (end - start)/2;
    if(arr[mid] == target) return mid;

    if(arr[start] <= arr[mid]){
        if(arr[start]  <= target && target <= arr[mid]){
           return Binary_Search(arr, start, mid-1, target);
        }else{
           return Binary_Search(arr, mid+1, end, target);
        }
    }else{
       if(arr[mid] <= target && target <= arr[end]){
        return Binary_Search(arr, mid+1, end, target);
       }else{
        return Binary_Search(arr, start, mid-1, target);
       }
    }
}
int main(){
    	vector<int> x = {4, 5, 6, 7, 0, 1, 2};
	    cout<<Binary_Search(x, 0, x.size()-1, 0);
        return 0;
}