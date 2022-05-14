#include<unordered_map>
#include<list>
#include<queue>


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
	
	unordered_map<int, list<int>> adj;
	
	for(int i = 0;i < edges.size();i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		
		adj[u].push_back(v);
	}
	
	vector<int> indegree(v);
	vector<int> ans;
	
	for(auto i : adj) {
		for(auto j : i.second) {
			indegree[j]++;
		}
	}
	
	queue<int> q;
	for(int i = 0;i < v;i++) {
		if(indegree[i] == 0) {
			q.push(i);
		}
	}
	
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		
		ans.push_back(front);
		
		for(auto i: adj[front]) {
			indegree[i]--;
			
			if(indegree[i] == 0) {
				q.push(i);
			}
		}
		
		
	}
	
	
	return ans;
}
