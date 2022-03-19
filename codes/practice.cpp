#include <iostream>
#include <bits/stdc++.h>

const int N = 1e4;
using namespace std;
class DFS{
	vector<int> graph[N];
	bool visited[N];
	public:
	void input(){
		int nodes,edges;
		cin>>nodes>>edges;
		int x ,y;
		for(int i = 0;i<edges;i++){
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		int start;
		cout<<"Enter the starting node : ";
		cin>>start;
		perform(start);
	}
	void perform(int start){
		cout<<start<<" ";
		if(!visited[start]){
			visited[start] = true;
			for(auto it = graph[start].begin();it!=graph[start].end();it++){
				if(!visited[*it])
					perform(*it);		
			}
		}
	}
};

int main(){
	DFS d;
	d.input();

	return 0;
}
