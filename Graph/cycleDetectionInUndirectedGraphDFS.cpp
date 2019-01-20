#include <bits/stdc++.h>
using namespace std;

bool dfsUtils(vector<vector<int>> &g,int node,int prevNode,int n,vector<bool> &visited){
    visited[node]=true;
    for(auto it=g[node].begin();it!=g[node].end();it++){
        if(visited[(*it)]==true){
            if((*it)!=prevNode){
                return true;
            }
        }else{
            if(dfsUtils(g,(*it),node,n,visited)){
                return true;
            }
        }
    }
    return false;
}
bool cyclePresent(vector<vector<int>> &g,int n){
    vector<bool> visited;
    visited.assign(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfsUtils(g,i,-1,n,visited)){
                return true;
            }
        }
    }
    return false;
}
int main() {
	int v,e;
	cin>>v>>e;
	vector<vector<int>> g;
	g.assign(v,vector<int>());
	int a,b;
	for(int i=0;i<e;i++){
	    cin>>a>>b;
	    g[a].push_back(b);
	    g[b].push_back(a);
	}
	if(cyclePresent(g,v)){
	    cout<<"Cyctel Present in this undirected Graph"<<endl;
	}else{
	    cout<<"Cycle Not Present in this undirected Graph"<<endl;
	}
	return 0;
}

/*
Input:
Conected Graph:
6 6
0 5
0 1
1 2
2 3
3 4
4 1

Unconnected Graph:

6 5
0 5
1 2
2 3
3 4
4 1
Output:
Cyctel Present in this undirected Graph
Cyctel Present in this undirected Graph
*/