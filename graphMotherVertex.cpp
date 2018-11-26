#include <bits/stdc++.h>
using namespace std;
void DFSUtils(vector<vector<int>> &g,vector<bool> &visited,int i){
    visited[i]=true;
    for(auto it=g[i].begin();it!=g[i].end();it++){
        if(!visited[*it]){
            DFSUtils(g,visited,*it);
        }
    }
}
void DFS(vector<vector<int>> &g,int n){
    int motherVertex=0;
    vector<bool> visited;
    visited.assign(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            motherVertex=i;
            DFSUtils(g,visited,i);
        }
    }
    cout<<motherVertex<<endl;// Mother vertex has the last finished time in DFS
}
int main() {
    int n,e;
    cin>>n>>e;
	vector<vector<int>> g;
	g.assign(n,vector<int>());
	int u,v;
	for(int i=0;i<e;i++){
	    cin>>u>>v;
	    g[u].push_back(v);
	}
	DFS(g,n);
}
