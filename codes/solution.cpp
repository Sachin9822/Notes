#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first 
#define ss second 
#define setBits(x) builtin_popcount(x)

const int N=1e5+2,MOD=1e9+7;
vi adj[N];

signed main(){
	int node,edges;

	std::vector<int> v[10];
	cout<<"Enter node and edges: ";
	cin>>node>>edges;

	cout<<"node is "<<node<<"Edge is "<<edges<<endl;
	vvi adjm(node+1,vi(node+1,0));

	rep(i, 0, edges){
		cout<<"Loop is running: ";
		int x,y;
		cin >> x >>y;
		
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout<<"adjacent list view : \n";
	rep(i, 1, edges){
			cout<<i<<" -> ";
		for(auto a: adj[i])
			cout<<a<<" ";
		cout<<endl;
	}

	rep(i,1,node+1){
		rep(j,1,node+1){
			cout<<adjm[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
