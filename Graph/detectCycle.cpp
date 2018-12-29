#include <bits/stdc++.h>
using namespace std;
bool checkIfAncistor(int u,int par,int parent[],int n){
    int p = parent[u];
    if(p!= -1){
        while(p!=-1){
            if(p==par){
                return true;
            }
            p = parent[p];
        }
    }
    return false;
}
bool ifCycelPresent(vector<vector<int>> &g,bool visited[],int n,int u,int parent[]){
    visited[u]=true;
    for(auto it=g[u].begin();it!=g[u].end();it++){
        if(!visited[(*it)]){
            parent[(*it)]=u;
            return ifCycelPresent(g,visited,n,(*it),parent);
        }else{
            if(checkIfAncistor(u,(*it),parent,n)){
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
	}
	bool foundCycle =false;
	bool visited[v];
	int parent[v];
	for(int i=0;i<v;i++){
	    parent[i]=-1;
	    visited[i]=false;
	}
	for(int i=0;i<v;i++){
	    if(!visited[i]){
	       if(ifCycelPresent(g,visited,v,i,parent)){
        	    cout<<"Found Cycle in the Graph"<<endl;
        	    foundCycle=true;
        	} 
	    }
	    if(foundCycle){
	        break;
	    }
	}
	if(!foundCycle){
	    cout<<"Cycle Not Found"<<endl;
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
Found Cycle in the Graph
*/