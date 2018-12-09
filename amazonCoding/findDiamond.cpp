#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> &grid,int n,int m,int x,int y){
    if(x>=0 && x<n && y>=0 && y<m){
        if(grid[x][y]!=INT_MAX && (grid[x][y]==-1 || grid[x][y]==INT_MIN)){
            return true;
        }
    }
    return false;
}
int bfs(vector<vector<int>> &grid,int n,int m,int whx,int why){
	int movx[]={-1,0,1,0};
	int movy[]={0,1,0,-1};
	queue<pair<int,int>> q;
	q.push(make_pair(whx,why));
	int dist=0;
	int toReturn=-1;
	while(!q.empty() && grid[q.front().first][q.front().second]!=INT_MIN ){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		dist= grid[x][y]+1;
		for(int i=0;i<4;i++){
			int newx=x+movx[i];
			int newy=y+movy[i];
			if(isSafe(grid,n,m,newx,newy)){
				q.push(make_pair(newx,newy));
				if(grid[newx][newy]!=INT_MIN){
				    grid[newx][newy]=dist;
				}else{
				    toReturn=dist;
				}
			}
		}
	}
	if(q.empty()){
		return -1;
	}else{
	    cout<<q.front().first<<" "<<q.front().second<<endl;
		return toReturn;
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> grid;
	grid.assign(n,vector<int>());
	for(int i=0;i<n;i++){
		grid[i].assign(m,-1);
	}
	int k;//obstrucle
	cin>>k;
	for(int i=0;i<k;i++){
		int x,y;
		cin>>x>>y;
		grid[x][y]=INT_MAX;
	}
	int whx,why;
	cin>>whx>>why;
	grid[whx][why]=0;

	int p;//number of person
	int x,y;
	cin>>p;
	for(int i=0;i<p;i++){
		cin>>x>>y;
		grid[x][y]=INT_MIN;
	}
	cout<<bfs(grid,n,m,whx,why);
}
/*
5 6
6
0 1
1 3
2 4
2 5
3 2
4 1
2 3
4
4 0
1 4
1 5
1 0
*/