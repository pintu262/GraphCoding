#include <bits/stdc++.h>
using namespace std;
// Find all the strongly connected Component in a directed graph.
// A strongly connected component is a sub-graph or set of nodes which hold a property that, each node is reachable from
// every other node in the set.
// KasaRaju's Two Pass Algorithm is used to solve it. 
// In Pass I: It get the finished time in decreading order of the dfs applied on the graph.
// In Pass II: revert the edge of the graph and go to explore (use dfs traversal) for each unvisited node in the set or list
void dfsPassI(vector<vector<int>> &g,int v,int node,vector<bool> &visited,stack<int> &s){
    visited[node]=true;
    for(auto it=g[node].begin();it!=g[node].end();it++){
        if(!visited[(*it)]){
            dfsPassI(g,v,(*it),visited,s);
        }
    }
    s.push(node);
}
void dfsPassIIUtils(vector<vector<int>> &gRev,int v,int node,vector<bool> &visited){
    visited[node]=true;
    cout<<node<<" ";
    for(auto it=gRev[node].begin();it!=gRev[node].end();it++){
        if(!visited[(*it)]){
            dfsPassIIUtils(gRev,v,(*it),visited);
        }
    }
}
void dfsPassII(vector<vector<int>> &gRev,int v,vector<bool> &visited,stack<int> &s){
    while(!s.empty()){
        int node = s.top();s.pop();
        if(!visited[node]){
            dfsPassIIUtils(gRev,v,node,visited);
            cout<<endl;
        }
    }
}
void reverseGraphEdge(vector<vector<int>> &g,vector<vector<int>> &gRev,int v){
    for(int i=0;i<v;i++){
        for(auto it=g[i].begin();it!=g[i].end();it++){
            gRev[(*it)].push_back(i);
        }
    }
}
void printSCC(vector<vector<int>> &g,int v){
    stack<int> s;// store the node decreasing order of their finish time;
    vector<bool> visited;
    visited.assign(v,false);
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            dfsPassI(g,v,i,visited,s);
        }
    }
    visited.assign(v,false);
    vector<vector<int>> gRev;
    gRev.assign(v,vector<int>());
    
    reverseGraphEdge(g,gRev,v);
    dfsPassII(gRev,v,visited,s);
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
	}
	printSCC(g,v);
	return 0;
}

/*
Input:
11 13
0 1
1 2
2 0
1 3
3 4
4 5
5 3
6 5
6 7
7 8
8 9
9 6
9 10
Output:
6 9 8 7 
10 
0 2 1 
3 5 4 
*/