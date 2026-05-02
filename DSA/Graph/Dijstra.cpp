#include<bits/stdc++.h>
using namespace std;

class Graph{
    vector<vector<pair<int, int>>>adjList;
    public:
    Graph(int n){
        adjList.resize(n);
    }
    void addEdge(int u, int v, int w){
        adjList[u].push_back(make_pair(w, v));
        adjList[v].push_back(make_pair(w, u));
    }

    vector<int>ShortestPath(int src){
        priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>
        >pq;
        vector<int>dist(adjList.size(), INT_MAX);

        dist[src] = 0;
        pq.emplace(0, src);

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int d = top.first;
            int u = top.second;

            if(d > dist[u]){
                continue;
            }

            for(auto &node : adjList[u]){
                int v = node.second;
                int w = node.first;

                if(dist[u]+w < dist[v]){
                    dist[v] = dist[u]  + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        return dist;
    }

    void showList(){
        
        for(auto i : adjList){
            for(auto j : i){
                cout<<"("<<j.first<<" "<<j.second<<") ";
            }
            cout<<endl;
        }
    }
};



int main(){
    int V, E;
    cin>>V>>E;
    Graph g(V);
    for(int i = 0; i<E; i++){
        int u, v, w;
        cin>>u>>v>>w;
        g.addEdge(u, v, w);
    }

    // g.showList();

    for(auto i : g.ShortestPath(0)){
        cout<<i<<" ";
    }
}