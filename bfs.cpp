#include<unordered_map>
#include<queue>
#include<set>

void adjList(unordered_map<int, set<int>> &mapping, vector<pair<int, int>> edges) {
	for(int i = 0;i < edges.size();i++) {
		int u = edges[i].first;
		int v = edges[i].second;
		
		mapping[u].insert(v);
		mapping[v].insert(u);
	}
}

void bfs(unordered_map<int, set<int>> &mapping, unordered_map<int, bool> &visited,
		vector<int> &ans, int node) {
	queue<int> q;
	q.push(node);
	visited[node] = 1;
	
	while(!q.empty()) {
		int frontNode = q.front();
		q.pop();
		
		ans.push_back(frontNode);
		
		for(auto i: mapping[frontNode]) {
			if(!visited[i]) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
	
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
	unordered_map<int, set<int>> mapping;
	adjList(mapping, edges);
	
	vector<int> ans;
	unordered_map<int, bool> visited;
	
	for(int i = 0;i < vertex;i++) {
		if(!visited[i]) {
			bfs(mapping, visited, ans, i);
		}
	}
	
	return ans;
}
