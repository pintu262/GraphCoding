#include <bits/stdc++.h>
using namespace std;
bool cyclePresentUtils(vector<vector<int>> &g,int v,int node,vector<int> &visited,map<int,int> &nodeAndPrev,int &cycleNode,int &nextCycleNode){
    visited[node]=1;
    for(auto it=g[node].begin();it!=g[node].end();it++){
        if(visited[*it]==1){
            nodeAndPrev.insert(make_pair((*it),node));
            cycleNode = node;
            nextCycleNode = (*it);
            return true;
        }else if(visited[*it]==0){
            nodeAndPrev.insert(make_pair((*it),node));
            if(cyclePresentUtils(g,v,(*it),visited,nodeAndPrev,cycleNode,nextCycleNode)){
                if(cycleNode == -1){
                    cycleNode = node;
                    nextCycleNode = (*it);
                }
                return true;
            }
        }
    }
    visited[node]=2;
    return false;
}
void printCycleFound(map<int,int> &nodeAndPrev,int &cycleNode,int &nextCycleNode){
    int nextNode = nodeAndPrev[cycleNode];
    stack<int> st;
    st.push(nextCycleNode);
    st.push(cycleNode);
    while(nextNode != -1 && nextNode != nextCycleNode){
        st.push(nextNode);
        nextNode = nodeAndPrev[nextNode];
    }
    
    cout<<nextCycleNode<<"->";
    while(!st.empty()){
        int val=st.top();
        st.pop();
        if(!st.empty()){
            cout<<val<<"->";
        }else{
            cout<<val;
        }
    }
    cout<<endl;
}
void cyclePresent(vector<vector<int>> &g,int v,map<int,int> &nodeAndPrev,int &cycleNode,int &nextCycleNode){
    vector<int> visited;
    visited.assign(v,0);
    
    for(int i=0;i<v;i++){
        if(visited[i]==0){
            nodeAndPrev.insert(make_pair(i,-1));
            if(cyclePresentUtils(g,v,i,visited,nodeAndPrev,cycleNode,nextCycleNode)){
                cout<<"Cycle Found is: ";
	            printCycleFound(nodeAndPrev,cycleNode,nextCycleNode);
            }
        }
    }
    // return cyclePresentUtils(g,v,0,visited,nodeAndPrev);
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
	map<int,int> nodeAndPrev;
	int cycleNode=-1;
	int nextCycleNode=-1;
	cyclePresent(g,v,nodeAndPrev,cycleNode,nextCycleNode);
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

6 7
0 1
1 2
2 0
0 3
3 5
5 4
4 3

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

*/