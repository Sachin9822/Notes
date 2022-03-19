#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int nodes,edges;cin>>nodes>>edges;
	vector<vector<int>> adj(nodes);
	vector<int> indegree(nodes,0);

	for(int i = 0;i<edges;i++){
		int x,y;cin>>x>>y;

		adj[x].push_back(y);
		indegree[y]++;
	}

	queue<int> q;
	for(int i = 0;i<nodes;i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		cout<<node<<endl;
		for(auto it: adj[node]){
			indegree[it]--;
			if(indegree[it]==0){
				q.push(it);
			}
		}
	}
	return 0;
}
