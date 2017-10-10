/*
	Author    :Bhuvanachandu
    	Title	  : Graph Cycle Detection
	Date      : Tue 10 Oct 2017 12:35:25 PM IST
*/
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
#define rep0(i,n) for(int i=0;i<n;i++)
#define rep(i,a,n) for(int i=(a);i<n;i++)
#define rRep(i,a,n) for(int i=(a);i>n;i--)
#define fore(i,a) for(auto &i:a)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define F first
#define S second
using LL = long long;
using ULL = unsigned long long;
void _main();
int main(){ ios::sync_with_stdio(0);cin.tie(0);_main();return 0;}
void addEdge(vector<int> adj[], int u, int v){
	adj[u].PB(v);
	adj[v].PB(u);
 	return;
}
bool dfsUtil(int u, vector<int> adj[], vector<bool> & visited){

	visited[u]=true;
	cout<<u<<" ";
	rep0(i,adj[u].size()){
		if(!visited[adj[u][i]]) dfsUtil(adj[u][i],adj, visited);
		else return true;
	}
	return false;
}
bool dfs(vector<int> adj[], int V){
	bool cycle=false;
	vector<bool> visited(V,false);
	rep0(i,V){
		if(!visited[i]) { if(dfsUtil(i,adj,visited)) return true;}
		else{ return true;}
	}
	return false;
}
void _main(){
	int V=5;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
  addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
   addEdge(adj, 3, 4);
	cout<<(dfs(adj, V)?"Cycle Detected":"No Cycle Found")<<endl;
}
