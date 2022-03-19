#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 1e3+5;
const int INF = 1e9;
class prims{
  vector<vector<int>> graph[N];
  int cost;
  public:
  prims(){
    cost = 0;
  }
  void Prims_algo(int source){
  vector<int> parent(N);
  vector<int> distance(N);
  vector<bool> visited(N);
    for(int i = 0;i<10000;i++){
      distance[i] = 1e9;
    }
    set<vector<int>> s;  
    s.insert({0,source});
    while(!s.empty()){
      auto x = *(s.begin());
      s.erase(x);
      visited[x[1]] = 1;
      int u = x[1];
      int v = parent[x[1]];
      int w = x[0];
      cout<<u<<" "<<v<<" "<<w<<endl;
      cost += w;   
      for(auto it : graph[x[1]]){
        if(visited[it[0]]){
          continue;
        }
        if(distance[it[0]] > it[1]){
          s.erase({distance[it[0]],it[0]});
          distance[it[0]] = it[1];
          s.insert({distance[it[0]],it[0]});
          parent[it[0]] = x[1];
          
        }
      }
    }
    cout<<"cost is "<<cost<<endl;
    exit(10);
  }
  void input_graph(){
    int n,m;
    cout<<"Enter the number of Nodes and edges: ";
    cin>>n>>m;
    int u,v,w;
    for(int i = 0;i<m;i++){
      cout<<"Enter the connected nodes and weight: ";
      cin>>u>>v>>w;
      graph[u].push_back({v,w});
      graph[v].push_back({u,w});
    }
      Prims_algo(0);
  }
};

int main() {
 prims p;
 p.input_graph(); 
}