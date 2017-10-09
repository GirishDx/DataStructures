	/*
	http://practice.geeksforgeeks.org/problems/trie-insert-and-search/0


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
#define Alphabet_Size 26
using LL = long long;
using ULL = unsigned long long;
void _main();
typedef struct Node{
	char data;
	struct Node * child[Alphabet_Size];
	bool isWord;
} node;
node * getEmptyNode(){
	node * temp = new node;
	rep0(i,Alphabet_Size) temp->child[i]=NULL;
	temp->isWord=false;
	return temp;
}
int getPositionOfChar(node * root, char key){
	rep0(i,Alphabet_Size) if((root->child[i]!=NULL)&&root->child[i]->data==key) return i;
	return -1;
}
void insert(node * root, string word,int index,int word_size){
	if(!root||index>=word_size||index<0) return;
	int p=getPositionOfChar(root,word[index]);
	if(p>=0){
		if(!root->child[p]->isWord)
		root->child[p]->isWord=(index==word_size-1?true:false);
		insert(root->child[p],word,index+1,word_size);
	}
	else{
		
		root->child[word[index]-'a']=getEmptyNode();
		root=root->child[word[index]-'a'];
		root->data=word[index];
		if(!root->isWord)
		root->isWord=(index==word_size-1?true:false);
		
		 insert(root,word, index+1,word_size); 
	}	
	return;
}
bool isEmpty(node * root){
	rep0(i,Alphabet_Size) if(root->child[i]!=NULL) return false;
	return true;
}
int hasOneChild(node * root){
    if(!root) return 0;
    int count=0;
    rep0(i, Alphabet_Size) if(root->child[i]!=NULL) count++;
    return count;
}
node * getChild(node * root){
    if(!root) return NULL;
    rep0(i, Alphabet_Size) if(root->child[i]!=NULL) return root->child[i];
    
}
bool search(node * root){
	int p=hasOneChild(root);
	if(p!=1) return false;
	while(p==1){
	    root=getChild(root);
	    cout<<root->data;
	   p=hasOneChild(root);
	    
	}
	cout<<endl;
	return true;
}
int main(){ ios::sync_with_stdio(0);cin.tie(0);_main();return 0;}
void _main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
    	node * root=getEmptyNode();
    	root->data=3;
    	string words[n];
    	int word_size=n;
    	rep0(i,word_size) cin>>words[i];
    	rep0(i,word_size) insert(root,words[i],0,words[i].size());
    
    	if(!search(root)) cout<<-1<<endl;
    }
	return;
}
