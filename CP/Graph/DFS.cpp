#include <bits/stdc++.h>
using namespace std;


void dfsRecursive(int node, vector<vector<int>>& adjlist, vector<bool>& visited, vector<int>& dfs) {
    visited[node] = true;
    dfs.push_back(node);

    for (auto& it : adjlist[node]) {
        if (!visited[it]) {
            dfsRecursive(it, adjlist, visited, dfs);
        }
    }
}



int main() {
    int v, e;
    cin >> v >> e;

    vector<pair<int, int>> edges;
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }

    vector<vector<int>> adjlist(v);
    for (int i = 0; i < e; i++) {
        int x = edges[i].first;
        int y = edges[i].second;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }

    stack<int> st;
    vector<bool> visited(v, false);
    vector<int> dfs;

    st.push(0);
    visited[0] = true;

    while (!st.empty()) {
        int top = st.top();
        st.pop();

        dfs.push_back(top);

        // Push neighbors in reverse to get proper DFS order
        for (int i = adjlist[top].size() - 1; i >= 0; i--) {
            int it = adjlist[top][i];
            if (!visited[it]) {
                st.push(it);
                visited[it] = true;
            }
        }
    }

    for (auto &it : dfs) {
        cout << it << " ";
    }
}
