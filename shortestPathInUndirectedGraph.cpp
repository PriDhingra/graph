#include<unordered_map>
#include<list>
#include<queue>

void bfs(unordered_map<int, list<int>> &adj, unordered_map<int, int> &parent, 
		unordered_map<int, bool> &visited, int node) {
	
	queue<int> q;
	q.push(node);
	parent[node] = -1;
	visited[node] = true;
	
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		
		for(auto i : adj[front]) {
			if(!visited[i]) {
				visited[i] = true;
				q.push(i);
				parent[i] = front;
			}
		}
	}
	
}

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int, list<int>> adj;
	
	for(int i = 0;i < edges.size();i++) {
		int u = edges[i].first;
		int v = edges[i].second;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	unordered_map<int, int> parent;
	unordered_map<int, bool> visited; 
	
	queue<int> q;
	q.push(s);
	parent[s] = -1;
	visited[s] = true;
	
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		
		for(auto i : adj[front]) {
			if(!visited[i]) {
				visited[i] = true;
				parent[i] = front;
				q.push(i);
				
			}
		}
	}
	
	vector<int> ans;
	int dest = t;
	ans.push_back(t);
	
	while(dest != s) {
		dest = parent[dest];
		ans.push_back(dest);
	}
	
	reverse(ans.begin(), ans.end());
	return ans;
}
