#include<bits/stdc++.h>
using namespace std;

//part-1

int sum(int n){
    if(n == 0){
        return 0;
    }
    return n + sum(n-1);
}

int factorial(int n){
    if(n== 0 || n==1){
        return 1;
    }
    return n* factorial(n-1);
}

bool isSorted(vector<int>&arr, int i){
    if(i == arr.size()-1){
        return true;
    }
    if(arr[i] < arr[i-1]) return false;
    return isSorted(arr, i+1);
}

int firstoccurance(vector<int>arr, int i, int target){
    if(i == arr.size()) return -1;
    if(arr[i] == target){
         return i;
    }
    return firstoccurance(arr, i+1, target);
}


int lastOccurance(vector<int>arr, int i, int target){
    if(i == arr.size()) return -1;
    int indx = lastOccurance(arr, i+1, target);
    if(indx == -1 && arr[i] == target) return i;
    return indx;
}

int power(int x, int n){
    if ( n == 0) return 1;
    int halfpower = power(x, n/2);
    if(n&1) return halfpower*halfpower*x;
    else return halfpower*halfpower;
}

//part-2
// Find the number of possible different combination to fill a 4xn with tiles of dimention 4x1 units height and 1 unit width 

int tilingProblem(int n){
    if(n==0||n==1){
        return 1;
    }
    int ans_1 = tilingProblem(n-1);
    int ans_2 = tilingProblem(n-2);
    return ans_1+ans_2;
}

//Find Total ways in which friends can be paried up, each friend can be pair up once. 

int friendPairing(int n){
    if(n==1 || n==2){
        return n;
    }
    return friendPairing(n-1) + (n-1)*friendPairing(n-2);
}

// Print all binary string of size n with no consecituve 1

void binaryString(int n, int lastplace, string ans){
    if(n == 0) {
        cout<<ans<<endl;
        return;
    }
    if (lastplace != 1){
        binaryString(n-1, 0, ans+"0");
        binaryString(n-1, 1, ans+"1");
    }else{
          binaryString(n-1, 0, ans+"0");
    }
}


void binaryString(int n, string ans){
    if(n == 0) {
        cout<<ans<<endl;
        return;
    }
    if (ans[ans.size()-1] != '1'){
        binaryString(n-1,ans+"0");
        binaryString(n-1,ans+"1");
    }else{
          binaryString(n-1,ans+"0");
    }
}




void removeDuplicates(string str, string ans, int i, int map[26]){
    if(i == str.size()){
        cout<<"ans :" <<ans<<endl;
        return;
    }

    if(map[str[i]-'a']){
        removeDuplicates(str, ans, i+1, map);
    }else{
        map[str[i]-'a'] = true;
        removeDuplicates(str, ans+str[i], i+1, map);
    }
}


int main(){
//    vector<int>arr = {1, 5, 2, 7, 3, 9, 0, 7};
//    cout<<lastOccurance(arr, 0, 7);
    //   int map[26] = {false};
    //   removeDuplicates("talha", "", 0, map);
    string ans = "";
    binaryString(5, ans);
}
