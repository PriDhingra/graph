#include<unordered_map>
#include<list>

bool cycleUsingDFS(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited,
				  int node, int parent) {
	
	visited[node] = 1;
	
	for(auto i: adjList[node]) {
		if(!visited[i]) {
			bool isCycleDetected = cycleUsingDFS(adjList, visited, i, node);
			if(isCycleDetected) {
				return true;
			}
		} else if(i != parent) {
			return true;
		}
	}
	return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
	unordered_map<int, list<int>> adjList;
	
	for(int i = 0;i < edges.size();i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	unordered_map<int, bool> visited;
	
	for(int i = 1;i <= n;i++) {
		if(!visited[i]) {
			bool ans = cycleUsingDFS(adjList, visited, i, -1);
			
			if(ans) {
				return "Yes";
			}
		}
	}
	return "No";
}


