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
void _main(){
	int n=5;
	int f[5]={1,2,3,4,5};
	int j, BIT[5]={0};
	rep(i,1,n){
		j=i;
		while(j<n){
			BIT[j]+=f[i];
			j+=j&-j;
		}
	}
	j=0;
	for(int k=1;k<n;k++) cout<<BIT[k]<<" ";
	cout<<endl;
}
