#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int>b){
    return b.second > a.second; 
}


int maximum(vector<pair<int, int>>x){
    int n = x.size();
    sort(x.begin(), x.end(), compare);

    int ans = 1;
    int curr_end = x[0].second;
    
    for(int i = 0; i<n; i++){
        if(x[i].first > curr_end){
            ans++;
            curr_end = x[i].second;
        }
    }

    return ans;

}


int main(){
    int n = 5;
    vector<pair<int, int>>pairs(n, make_pair(0, 0));
    pairs[0] = make_pair(1, 5);
     pairs[1] = make_pair(39, 60);
      pairs[2] = make_pair(5, 20);
       pairs[3] = make_pair(6, 24);
        pairs[4] = make_pair(7, 30);
    
        cout<<maximum(pairs);

}