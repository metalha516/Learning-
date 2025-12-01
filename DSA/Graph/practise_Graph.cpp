#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    vector<vector<int>>Edges;
    bool undirected;
    Graph(int n, bool undirected = true){
        Edges.resize(n);
        this->undirected = undirected;
    }

    void addEdge(int u, int v){
        Edges[u].push_back(v);
        if(undirected)
        Edges[v].push_back(u);
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
            for(auto v : Edges[curr]){
                if(!visited[v])  {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void DFS_(int src, vector<bool>&vis){
        cout<<src<<" ";
        vis[src] = true;
        for(auto &v : Edges[src]){
            if(!vis[v]){
                DFS_(v, vis);
            }
        }
    }
    
    void DFS(int src){
        vector<bool>visited(Edges.size(), false);
        DFS_(src, visited);
        cout<<endl;
    }


    bool isCycle_(int src, vector<bool>&vis, vector<bool>&rec){
         vis[src] = true;
         rec[src] = true;
         for(auto &v : Edges[src]){
            if(!vis[v]){
               if(isCycle_(v, vis, rec)) return true;
            }else{
               if(rec[v]) return true;
            }
         }
         rec[src] = false;
         return false;
    }

    bool isCycle(){
        vector<bool>visited(Edges.size(), false);
        vector<bool>rec(Edges.size(), false);
        for(int i = 0; i<Edges.size(); i++){
            if(!visited[i]){
                if(isCycle_(i, visited, rec)) return true;
            }
        } 
        return false;
    }
    void toposort_(int src, vector<bool>&vis, stack<int>&st){
        vis[src] = true;
        for(auto v : Edges[src]){
            if(!vis[v]){
                toposort_(v, vis, st);
            }
        }
        st.push(src);
    }
    void toposort(){
        vector<bool>vis(Edges.size(), false);
        stack<int>st;
        for(int i = 0; i<Edges.size(); i++){
            if(!vis[i]){
                toposort_(i, vis, st);
            }
        }
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
    }

    void print(){
        for(int i = 0; i<Edges.size(); i++){
            cout<<i<<" -> ";
            for(auto &it : Edges[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }


};

int main(){
    int v, e;
    cin>>v>>e;
    Graph graph(v, false);
    for(int i = 0; i<e; i++){
        int u, v;
        cin>>u>>v;
        graph.addEdge(u, v);
    }
    graph.toposort();
    return 0;
}