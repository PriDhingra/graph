#include<algorithm>
void makeSet(vector<int> &parent, vector<int> &rank, int n) {
    for(int i = 0;i < n;i++) {
        rank[i] = 0;
        parent[i] = i;
    }
}

int findParent(vector<int> &parent, int node) {
    if(parent[node] == node) {
        return node;
    }
    
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(parent, u);
    v = findParent(parent, v);
    
    if(rank[u] < rank[v]) 
        parent[u] = v;
    else if(rank[v] < rank[u])
        parent[v] = u;
    else if(rank[u] == rank[v]) {
        parent[v] = u;
        rank[u]++;
    }
}

bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);
    
    int minWeight = 0;
    
    for(int i = 0;i < edges.size();i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int w = edges[i][2];
        
        if(u != v) {
            minWeight += w;
            unionSet(u, v, parent, rank);
        }
    }
    
    return minWeight;
}
