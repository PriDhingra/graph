#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<limits.h>

using namespace std;

class Graph {
    public: 
        unordered_map<int, list<pair<int, int>>> adj;
        stack<int> s;

    void createEdge(int start, int end, int weight) {
        pair<int, int> p = make_pair(end, weight);
        adj[start].push_back(p);
    }

    void printGraph() {
        for(auto i: adj) {
            cout<<i.first<<" -> ";
            for(auto j: i.second) {
                cout<<'{'<<j.first<<","<<j.second<<"}, ";
            }
            cout<<"\n";
        }
    }

    void dfs(unordered_map<int, bool> &visited, stack<int> &s, int node) {
        visited[node] = true;

        for(auto i: adj[node]) {
            if(!visited[i.first]) {
                dfs(visited, s, i.first);
            }
        }

        s.push(node);
    }

    void getShortestPath(int src, vector<int> &dist, stack<int> &s) {
        dist[src] = 0;

        while(!s.empty()) {
            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX) {
                for(auto i: adj[top]) {
                    if(dist[top] + i.second < dist[i.first]) {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }

};

int main() {
    Graph g;
    g.createEdge(0, 1, 5);
    g.createEdge(0, 2, 3);
    g.createEdge(1, 2, 2);
    g.createEdge(1, 3, 6);
    g.createEdge(2, 3, 7);
    g.createEdge(2, 4, 4);
    g.createEdge(2, 5, 2);
    g.createEdge(3, 4, -1);
    g.createEdge(4, 5, -2);

    g.printGraph();

    int n = 6;
    unordered_map<int, bool> visited;
    stack<int> s;

    for(int i = 0;i < n;i++) {
        if(!visited[i]) {
            g.dfs(visited, s, i);
        }
    }

    vector<int> dist(n);
    for(int i = 0;i < n;i++) {
        dist[i] = INT_MAX;
    }

    int src = 1;

    g.getShortestPath(src, dist, s);

    for(int i = 0;i < n;i++) {
        cout<<dist[i]<<" ";
    }

    return 0;
}
