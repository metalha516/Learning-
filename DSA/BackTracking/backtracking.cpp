#include<bits/stdc++.h>
using namespace std;

void print(int arr[]){
    for(int i =0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void changeArray(int arr[], int i, int n){
    if(i==n){
        print(arr);
        return;
    }

    arr[i] = i+1; //before function call & it goes down in call stack
    changeArray(arr, i+1, n);
    arr[i]-=2; //after function call & it goes up in call stack (backtracking)
}

int main(){
    int arr[5] = {0};
    changeArray(arr, 0, 5);
    print(arr);
}