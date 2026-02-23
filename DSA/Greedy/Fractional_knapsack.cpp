#include<bits/stdc++.h>
using namespace std;

int compare(pair<int, int>x, pair<int, int>y){
    return x.first > y.first;
}


int fractional_knapsack(vector<int>val, vector<int>wt, int W){
    int n = val.size();
    vector<pair<int, int>>ratio(n, make_pair(0.0, 0));
    for(int i = 0; i<n; i++){
        double r = val[i]/(double)wt[i]; // per kg
        ratio[i] = make_pair(r, i);
    }
    sort(ratio.begin(), ratio.end(), compare);
    int ans = 0;
    for(int i = 0; i<n; i++){
        int indx = ratio[i].second; // wt, val
        if(wt[indx] <= W){
            ans+=val[indx];
            W-=wt[indx];
        }else{
            ans+=ratio[i].first * W;
            W= 0;
            break;
        }
    }
    return ans;
}

int main(){
    vector<int> val = {1, 6, 3};
    vector<int>wt = {4, 5, 2};
    int W = 6;
    cout<<"Maxium Value : "<<fractional_knapsack(val, wt, W);
}