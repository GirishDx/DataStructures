/*
	Author    :Bhuvanachandu
	Title	  : Graph Depth First Traversal 
	Date      : Tue 10 Oct 2017 11:42:00 AM IST
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
void dfsUtil(int u, vector<int> adj[], vector<bool> & visited){

	visited[u]=true;
	cout<<u<<" ";
	rep0(i,adj[u].size()){
		if(!visited[adj[u][i]]) dfsUtil(adj[u][i],adj, visited);
	
	}

}
void dfs(vector<int> adj[], int V){

	vector<bool> visited(V,false);
	rep0(i,V){
		if(!visited[i]) dfsUtil(i,adj,visited);
	}
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
	dfs(adj, V);
}
