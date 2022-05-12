#include<unordered_map>
#include<list>
#include<queue>

bool cycleUsingBFS(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited,
				  int node, unordered_map<int, int> &parent) {
	
	queue<int> q;
	q.push(node);
	visited[node] = 1;
	parent[node] = -1;
	
	while(!q.empty()) {
		int frontNode = q.front();
		q.pop();
		
		for(auto i : adjList[frontNode]) {
			if(visited[i] == true && i != parent[frontNode]) {
				return true;
			} else if(!visited[i]) {
				q.push(i);
				visited[i] = 1;
				parent[i] = frontNode;
			}
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
	unordered_map<int, int> parent;
	
	
	for(int i = 1;i <= n;i++) {
		if(!visited[i]) {
			bool ans = cycleUsingBFS(adjList, visited, i, parent);
			
			if(ans) {
				return "Yes";
			}
		}
	}
	return "No";
}


