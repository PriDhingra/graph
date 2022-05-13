#include<unordered_map>
#include<list>

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, 
				  unordered_map<int, bool> dfsVisit, unordered_map<int, list<int>> &adj,
				  int parent) {
	
	visited[node] = true;
	dfsVisit[node] = true;
	
	for(auto i : adj[node]) {
		if(!visited[i]) {
			bool cycleDetected = checkCycleDFS(i, visited, dfsVisit, adj, node);
			if(cycleDetected) {
				return true;
			}
		} else if(dfsVisit[i] == true) {
				return true;
			
		}
	}
	
	dfsVisit[node] = false;
	return false;
	
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
	unordered_map<int, list<int>> adj;
	
	for(int i = 0;i < edges.size();i++) {
		int u = edges[i].first;
		int v = edges[i].second;
		
		adj[u].push_back(v);
	}
	
	unordered_map<int, bool> visited;
	unordered_map<int, bool> dfsVisit;
	
	for(int i = 1;i <= n;i++) {
		if(!visited[i]) {
			bool cycleFound = checkCycleDFS(i, visited, dfsVisit, adj, -1);
			if(cycleFound) {
				return true;
			}
		}
	}
	
	return false;
}
