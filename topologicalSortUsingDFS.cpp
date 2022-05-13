#include<unordered_map>
#include<list>
#include<stack>

void dfs(unordered_map<int, list<int>> &adj, vector<bool> &visited,
		stack<int> &s, int node) {
	
	visited[node] = true;
	
	for(auto i: adj[node]) {
		if(!visited[i])
			dfs(adj, visited, s, i);
	}
	
	s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
	stack<int> s;
	
	unordered_map<int, list<int>> adj;
	
	for(int i = 0;i < edges.size();i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		
		adj[u].push_back(v);
	}
	
	vector<bool> visited(v);
	
	for(int i = 0;i < v;i++) {
		if(!visited[i]) {
			dfs(adj, visited, s, i);
		}
	}
	
	vector<int> ans;
	if(v == 0) {
		ans.push_back(0);
		return ans;
	}
		
	while(!s.empty()) {
		ans.push_back(s.top());
		s.pop();
	}
	
	return ans;
}
