#include<unordered_map>
#include<list>

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, 
        unordered_map<int, bool> &visited, vector<vector<int>> &result, 
        unordered_map<int, list<int>> &adj) {
    
    visited[node] = true;
    disc[node] = low[node] = timer++;
    
    for(auto nbr: adj[node]) {
        if(nbr == parent)
            continue;
        
        if(!visited[nbr]) {
            dfs(nbr, node, timer, disc, low, visited, result, adj);
            low[node] = min(low[node], low[nbr]);
            
            if(low[nbr] > disc[node]) {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
            
        } else {
            low[node] = min(low[node], disc[nbr]);
        }
    }
    
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int, list<int>> adj;
    
    for(int i = 0;i < edges.size();i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int, bool> visited;
    vector<vector<int>> result;
    int timer = 0;
    
    for(int i = 0;i < v;i++) {
        disc[i] = -1;
        low[i] = -1;
    }
    
    for(int i = 0;i < v;i++) {
        if(!visited[i])
            dfs(i, parent, timer, disc, low, visited, result, adj);
    }
    
    return result;
}
