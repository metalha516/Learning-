#include<bits/stdc++.h>
using namespace std;

class Graph{
  
    vector<vector<int>>adjList;
    bool undirected;
    public:
    Graph(int n, bool undirected = true){
        adjList.resize(n);
        this->undirected = undirected;
    }

    void addedge(int u, int v){
        adjList[u].push_back(v);
        if(undirected){
            adjList[v].push_back(u);
        }
    }

    vector<int>BFS(int src){
        queue<int>q;
        vector<bool>visited(adjList.size(), false);
        vector<int>res;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for(auto edge : adjList[curr]){
                if(!visited[edge]){
                    visited[edge] = true;
                    q.push(edge);
                }
            }
        }
        return res;
    }
    
};

int main(){
    int vertices, edges;
    cin>>vertices>>edges;
    Graph g(vertices, true);
    for(int i = 0; i<edges; i++){
        int u, v;
        cin>>u>>v;
        g.addedge(u, v);
    }

    int src;
    cin>>src;

    for(auto i : g.BFS(src)){
        cout<<i<<" ";
    }

}