#include <iostream>
#include <bits/stdc++.h>

const int N = 1e5+1;
using namespace std;
vector<int> parent(N);
vector<int> s(N);

void make_set(int v){
	parent[v] = v;
	s[v] = 1;
}
int find_set(int v){
	if(parent[v] == v){
		return v;
	}
	return parent[v] = find_set(v);
}
void union_set(int a,int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		if(s[a]<s[b])
			swap(a,b);
		parent[b]=a;
		s[a] += s[b];
	}
}

int main(){
	for(int i = 0;i<N;i++){
		make_set(i);
	}
	int nodes,edges;
	cin>>nodes>>edges;
	vector<vector<int>> edge;
	for(int i=0;i<edges;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge.push_back({w,u,v});
	}
	sort(edge.begin(),edge.end());
	int cost = 0;
	for(auto a: edge){
		int w = a[0];
		int u = a[1];
		int v = a[2];
		int x = find_set(u);
		int y = find_set(v);
		if(x == y){
			continue;
		}
		else{
			cout<<u<<" "<<v<<"\n";
			cost += w;
			union_set(x, y);
		}
	}
	cout<<cost<<endl;
	return 0;
}
