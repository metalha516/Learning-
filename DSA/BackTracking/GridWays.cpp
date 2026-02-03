#include<bits/stdc++.h>
using namespace std;

//Find number of ways to reach from (0,0) to (N-1, M-1) in a NxM grid

int gridways(int r, int c, int n, int m){
    if(r == n-1 && c == m-1){
        return 1;
    }

    if(r>=n || c>=m){
        return 0;
    }

    int move_1 = gridways(r+1, c, n, m);
    int move_2 = gridways(r, c+1, n, m);
    return move_1+move_2;
}

int main(){
    cout<<gridways(0,0, 2,2);
}