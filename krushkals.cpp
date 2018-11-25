#include <bits/stdc++.h>
using namespace std;
struct mycomp{
    using is_transparent = int;
    bool operator()(const pair<pair<int,int>,int> &p1,const pair<pair<int,int>,int> &p2)const{//sort according to weight
        return p1.second<p2.second;
    }
    bool operator()(const pair<pair<int,int>,int> &p1,int u)const{//find in the set if u is present
        return p1.first.second<u;
    }
    bool operator()(int u,const pair<pair<int,int>,int> &p1)const{
        return u<p1.first.second;
    }
};

bool cycleFormed(vector<vector<pair<int,int>>> &st,vector<bool> visited,int u,int v,int w){
    if(visited[u]==true && visited[v]==true){
        return true;
    }
    return false;
}

void krushkalSt(vector<vector<pair<int,int>>> &g,vector<vector<pair<int,int>>> &st,int a,int n){
    multiset<pair<pair<int,int>,int>,mycomp> s; // set containg the edge and the weight and decide the order based on the weight 
    for(int u=0;u<n;u++){
        for(auto it=g[u].begin();it!=g[u].end();it++){
            // if(s.find(make_pair(make_pair((*it).first,u)),(*it).second)==s.end()){
                s.insert(make_pair(make_pair(u,(*it).first),(*it).second));
            // }
        }
    }
    
    vector<bool> visited;
    visited.assign(n,false);
    int u,v,w;
    auto setItPtr = s.begin();
    u=(*setItPtr).first.first;
    v=(*setItPtr).first.second;
    w=(*setItPtr).second;
    st[u].push_back(make_pair(v,w));
    visited[u]=true;
    visited[v]=true;
    s.erase(setItPtr);
    // cout<<u<<" "<<v<<" "<<w<<endl;
    for(int i=1;(i<(n-1))&&(!s.empty());i++){
        auto setIt=s.begin();
        s.erase(s.begin());
        u=(*setIt).first.first;
        v=(*setIt).first.second;
        w=(*setIt).second;
        if(cycleFormed(st,visited,u,v,w) ||visited[u]==false){
            i--;
        }else{
            st[u].push_back(make_pair(v,w));
            // cout<<u<<" "<<v<<" "<<w<<endl;
            visited[v]=true;
        }
    }
}
void printSpanningTree(vector<vector<pair<int,int>>> &st,int n){
    for(int i=0;i<n;i++){
        cout<<i<<"->";
        for(auto it=st[i].begin();it!=st[i].end();it++){
            cout<<"("<<(*it).first<<","<<(*it).second<<")->";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main() {
    int n,e;cin>>n>>e;

	vector<vector<pair<int,int>>> g;//not a DAG, single edge represent edge without direction
	g.assign(n,vector<pair<int,int>>());
	
	vector<vector<pair<int,int>>> st;
	st.assign(n,vector<pair<int,int>>());
	
	int a,u,v,w;
	cin>>u>>v>>w;
	a=u;
	g[u].push_back(make_pair(v,w));
	for(int i=0;i<(e-1)*2;i++){
	    cin>>u>>v>>w;
	    g[u].push_back(make_pair(v,w));
	   // g[v].push_back(make_pair(u,w));
	}
	
	krushkalSt(g,st,a,n);
	
	printSpanningTree(st,n);
}
/*
0->(2,1)->
1->
2->(1,2)->(3,4)->
3->(4,4)->
4->
*/