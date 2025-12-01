#include<bits/stdc++.h>
using namespace std;
int main(){
    int v, e;
    cin>>v>>e;
    vector<pair<int, int>>edges;
    for(int i = 0; i<e; i++){
        int x, y;
        cin>>x>>y;
        edges.push_back({x, y});
    }
    vector<vector<int>>adjlist(v);
    for(int i = 0; i<e; i++){
        int x = edges[i].first;
        int y = edges[i].second;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }

    for(int i = 0; i<v; i++){
        cout<<i<<"->"<<" ";
        for(auto &it : adjlist[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}