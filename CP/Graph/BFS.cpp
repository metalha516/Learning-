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

    queue<int>q;
    vector<bool>visited(v, false);
    vector<int>bfs;
    q.push(0);
    visited[0] = true;
    bfs.push_back(0);

    while(q.size() > 0){
        int front = q.front();
        q.pop();
        for(auto&it : adjlist[front]){
            if(!visited[it]){
                q.push(it);
                visited[it] = true;
                bfs.push_back(it);
            }
        }
    }
    
    for(auto &it : bfs){
        cout<<it<<" ";
    }

}