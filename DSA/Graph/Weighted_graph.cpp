#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    vector<vector<pair<int, int>>> Edges;
    Graph(int n){
        Edges.resize(n);
    }

    void addEdge(int u, int v, int w){
        Edges[u].push_back({v, w});
        Edges[v].push_back({u, w});
    }

    void print(){
        for(int i = 0; i<Edges.size(); i++){
            cout<<i<<" -> ";
            for(auto &it : Edges[i]){
               cout<<"("<<it.first<<" "<<it.second<<") ";
            }
            cout<<endl;
        }
    }


};

int main(){
    Graph g(5);
    g.addEdge(1, 0, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 4, 2);
    g.addEdge(2, 3, 1);
    g.print();    
}