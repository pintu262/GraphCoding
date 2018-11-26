#include <bits/stdc++.h>
using namespace std;
void DFSUtils(vector<vector<int>> &g,stack<int> &s,vector<bool> &visited,int i){
    visited[i]=true;
    for(auto it=g[i].begin();it!=g[i].end();it++){
        if(!visited[*it]){
            DFSUtils(g,s,visited,*it);
            s.push(*it);
        }
    }
    s.push(i);
}
void printSCC(vector<vector<int>> &cg,vector<bool> &visited,int i,int n){
    cout<<i<<" ";
    visited[i]=true;
    for(auto it=cg[i].begin();it!=cg[i].end();it++){
        if(!visited[*it]){
            printSCC(cg,visited,(*it),n);
        }
    }
}
void connectedComponent(vector<vector<int>> &g,vector<vector<int>> &cg,int n){
    vector<bool> visited;
    visited.assign(n,false);
    
    stack<int> s;//Insert as per finished Time
    
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            DFSUtils(g,s,visited,i);
        }
    }
    visited.assign(n,false);
    while(!s.empty()){
        int v=s.top();s.pop();
        if(!visited[v]){
            printSCC(cg,visited,v,n);
            cout<<endl;
        }
    }
}
int main() {
	int n,e;
	cin>>n>>e;
	vector<vector<int>> g;
	vector<vector<int>> cg;
	g.assign(n,vector<int>());
	cg.assign(n,vector<int>());
	int u,v;
	for(int i=0;i<e;i++){
	    cin>>u>>v;
	    g[u].push_back(v);
	    cg[v].push_back(u);
	}
	connectedComponent(g,cg,n);
}
