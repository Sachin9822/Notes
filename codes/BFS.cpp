#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+2;
class BFS{
	int node,edges;
	bool visited[N];
	vector<int> adj[N];
	public:
	void input(){
		for(int i =0;i<N;i++){
			visited[i] = false;
		} 
		cout<<"Enter the number of nodes: ";
		cin>>node;
		cout<<"Enter the number of edges: ";
		cin>>edges;
		int x,y;
		cout<<"Enter the edges \n";
		for(int i = 0;i<edges;i++){
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
	}
	void display(){
		cout<<"Breath first search: \n";
		std::queue<int> q;
		q.push(1);
		visited[1] = true;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			cout<<node<<" ";
			vector<int>::iterator it;
			for(it = adj[node].begin();it!=adj[node].end();it++){
				if(!visited[*it]){
					visited[*it] = true;
					q.push(*it);
				}
			}
		}
	}
};

int main(){
	BFS b;
	b.input();
	b.display();
	return 0;
}
