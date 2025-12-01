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
    int adjmat[v][v];
     for(int i = 0; i<v; i++){
        for(int j = 0; j<v; j++){
            adjmat[i][j] = 0;
        }
    }
    for(int i = 0; i<e; i++){
        int x = edges[i].first;
        int y = edges[i].second;
        adjmat[x][y] = 1;
    }

    for(int i = 0; i<v; i++){
        for(int j = 0; j<v; j++){
            cout<<adjmat[i][j]<<" ";
        }
        cout<<endl;
    }
}