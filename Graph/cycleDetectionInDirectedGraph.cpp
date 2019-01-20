#include <bits/stdc++.h>
using namespace std;
//If we encounter a node which is being in the exploring state(1) that means a cycle present in the graph
// state(0) - unvisited
// state(2) - explored Completely
bool cyclePresentUtils(vector<vector<int>> &g,int v,int node,vector<int> &visited){
    visited[node]=1;
    for(auto it=g[node].begin();it!=g[node].end();it++){
        if(visited[*it]==1){
            return true;
        }else if(visited[*it]==0){
            if(cyclePresentUtils(g,v,(*it),visited)){
                return true;
            }
        }
    }
    visited[node]=2;
    return false;
}
bool cyclePresent(vector<vector<int>> &g,int v){
    vector<int> visited;
    visited.assign(v,0);
    return cyclePresentUtils(g,v,0,visited);
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
	if(cyclePresent(g,v)){
	    cout<<"Cycle Present"<<endl;
	}else{
	    cout<<"Cycle Not Presnet"<<endl;
	}
	return 0;
}
/*
Input:
5 6
0 1
1 2
2 3
0 3
3 1
1 4
Output:
Cycle Present
*/