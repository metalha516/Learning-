#include<bits/stdc++.h>
using namespace std;
bool get_ith_bit(int num, int pos){
    return (num&(1<<pos)) ? true : false;
}

int countSetBit(int n){
    int count = 0;
    while(n > 0){
        int last_dig = n&1;
        count+=last_dig;
        n= n>>1;
    }
    return count;
}

int set_ith_bit(int num, int pos){
    return num |= (1<<pos);
}

int clear_ith_bit(int num, int pos){
    return num &= ~(1<<pos);
}

bool is_powerOf2(int n){
    return (n & (n-1)) ? false : true;
}
int update_bit(int num, int pos, int value){
    num &= ~(1<<pos);
    return num |= (value<<pos);
}

int clear_last_ith_bit(int x, int i){
    return x&((~0)<<i);
}

int main(){
    int num, pos;
    cin>>num>>pos;
    cout<<clear_ith_bit(num, pos-1)<<endl;
    cout<<is_powerOf2(num)<<endl;
    cout<<update_bit(num, pos-1, 1)<<endl;
    cout<<clear_last_ith_bit(num, pos)<<endl;
    cout<<countSetBit(num);
}

