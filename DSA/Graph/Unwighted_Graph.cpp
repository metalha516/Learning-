#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    vector<vector<int>>Edges;
    bool isUnDir;
    Graph(int n, bool isUnDir = true){
        Edges.resize(n);
        this->isUnDir = isUnDir;
    }

    void addEdges(int u, int v){
        Edges[u].push_back(v);
        if(isUnDir)
        Edges[v].push_back(u);
    }

    void print(){
       for(int i = 0; i<Edges.size(); i++){
          cout<<i<<" -> ";
          for(auto it : Edges[i]){
            cout<<it<<" ";
          }
          cout<<endl;
       }
    }
        
    void BFS(int src){
        queue<int>q;
        vector<bool>visited(Edges.size(), false);
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int curr = q.front();
            cout<<curr<<" ";
            q.pop();
            for(auto &it : Edges[curr]){
                if(visited[it] == false){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }    
    }

    void DFS(int src, vector<bool>&visited){
        cout<<src<<" ";
        visited[src] = true;
        for(auto &it : Edges[src]){
            if(!visited[it]){
                DFS(it, visited);
            }
        }
    }


    void DFS_runner(int src){
          vector<bool>visited(Edges.size(), false);
          DFS(src, visited);
          cout<<endl;
    }


    bool path_finder(int src, int dist, vector<bool>&vis){
           if(src == dist) return true;
           vis[src] = true;
           for(auto &it : Edges[src]){
               if(!vis[it]){
                    if(path_finder(it, dist, vis)) 
                    return true;
               }
           }
           return false;
    }
    // For Undirected graph
    bool cycleDetectionHelper(int src, int parent, vector<bool>&vis){
        queue<int>q;
        q.push(src);
        vis[src] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto &i : Edges[src]){
                if(!vis[i]){
                    if(cycleDetectionHelper(i, src, vis)) return true;
                }
                 else{
                        if(i!= parent) return true;
                    }
            }
        }

      return false;
    }

    bool cycleDetection(){
        vector<bool>visited(Edges.size(), false);
        return cycleDetectionHelper(0, -1, visited);
    }

    //For Directed Graph
    bool isCycleDirected(){
        vector<bool>vis(Edges.size(), false);
        vector<bool>recurs(Edges.size(), false);
        for(int i = 0; i<Edges.size(); i++){
            if(!vis[i]){
                if(directCycleHelper(i, vis, recurs)) return true;
            }
        }
        return false;
    }

    bool directCycleHelper(int src, vector<bool>&vis, vector<bool>&rec){
        vis[src] = true;
        rec[src] = true;

        for(int v : Edges[src]){
            if(!vis[v]){
                if(directCycleHelper(v, vis, rec)) return true;
            }else{
                 if(rec[v]){
                    return true;
                 }
            }
        }
        rec[src] = false;
        return false;
    }

    //checking is bipertite or not 

    bool isBipertite(){
        queue<int>q;
        vector<bool>vis(Edges.size(), false);
        vector<int>color(Edges.size(), -1);
        q.push(0);
        color[0] = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto &it : Edges[curr]){
                if(!vis[curr]){
                    vis[curr] = true;
                    color[it] = !color[curr];
                    q.push(it);
                }else{
                    if(color[it] == color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    //topological Sort

    void topoSortHelper(int src, vector<bool>& vis, stack<int>& s){
    vis[src] = true;

    for(auto v : Edges[src]){
        if(!vis[v]){
            topoSortHelper(v, vis, s);
        }
    }

    s.push(src);
}

void toposort(){
    vector<bool> visited(Edges.size(), false);
    stack<int> s;

    for(int i = 0; i < Edges.size(); i++){
        if(!visited[i]){
            topoSortHelper(i, visited, s);
        }
    }

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}


};


int main(){
    int v, e;
    cin>>v>>e;
    Graph g(v, false);
    for(int i = 0; i<e; i++){
        int u, v;
        cin>>u>>v;
        g.addEdges(u, v);
    }

    vector<bool>visited(g.Edges.size(), false);
    vector<bool>rec(g.Edges.size(), false);

   g.BFS(0);
    return 0;
}