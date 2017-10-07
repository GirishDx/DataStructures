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
void buildSegmentTree(int node, int i, int j, int A[],int segment_tree[]){

	if(i==j){
		segment_tree[node]=A[i]; return;
	}
	buildSegmentTree(2*node+1, i, (i+j)/2,A,segment_tree);// build left subtree <--> left child index= 2*node(if root==0)
	buildSegmentTree(2*node+2, (i+j)/2+1, j,A,segment_tree);// build right subtree <--> left right index= 2*node+1(if root==0)
	segment_tree[node]=segment_tree[2*node+1]+segment_tree[2*node+2]; // adding child nodes to parent node

}
int query(int node, int start, int end, int i, int j, int segment_tree[]){
	//(se < i || ss > j)
	if(start>j||end<i) return 0;//if the range doesnt fit in [start..end] return 0
	//(i <= ss && j >= se)
	if(i<=start&&j>=end) return segment_tree[node];
	int mid=(start+end)/2;
	int n=query(2*node+1,start,mid,i, j,segment_tree)+query(2*node+2,mid+1,end,i, j,segment_tree);
	return n;



}
void update(int node, int start, int end, int segment_tree[],int position, int value){
	if(start==end){
		segment_tree[node]=value;
		return;
	}
	int mid=(start+end)/2;
	if(position<=mid)// point is in left 
			update(2*node+1,start, mid, segment_tree,position,value);
	else
		update(2*node+2, mid+1, end, segment_tree,position,value);
	
	segment_tree[node]=segment_tree[2*node+1]+segment_tree[2*node+2];
	return;

}
int main(){ ios::sync_with_stdio(0);cin.tie(0);_main();return 0;}
void _main(){

	//int *A=new int[4];
	int A[]={2,1,3,4};
	int n=4;
	int segment_tree[2*n-1];
	buildSegmentTree(0,0,n-1,A,segment_tree);
	rep0(i,2*n-1) cout<<segment_tree[i]<<endl;
	update(0,0,n-1,segment_tree,0,5);
	rep0(i,2*n-1) cout<<segment_tree[i]<<endl;
//	cout<<query(0,0,n-1, 1,3, segment_tree)<<endl;;

}
