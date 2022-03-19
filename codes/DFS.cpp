#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+2;
class DFS{
	int nodes,edges;
	bool visited[N];
	vector<int> adj[N];
	public:
	void input(){
		for(int i =0;i<N;i++){
			visited[i] = false;			
		}
		cout<<"Enter the number of nodes: ";
		cin>>nodes;
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
	void display(int node){
		visited[node] = true;
		cout<<node<<" ";

		for(auto it = adj[node].begin();it!=adj[node].end();it++){
			if(!visited[*it]){
				display(*it);
			}
		}
	}
};

int main(){
	DFS d;
	d.input();
	d.display(2);
	return 0;
}
