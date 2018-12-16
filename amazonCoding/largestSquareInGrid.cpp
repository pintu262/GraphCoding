#include <bits/stdc++.h>
using namespace std;
// I can use matrix but for a change, vector is used
int largestSquare(vector<vector<int>> &M,int r,int c){
    int maxSquare=0;
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(M[i][j]==1){
                if(M[i-1][j-1]!=0 && M[i-1][j]!=0 && M[i][j-1]!=0){
                    M[i][j]=M[i-1][j-1]+1;
                    if(M[i][j] > maxSquare){
                        maxSquare=M[i][j];
                    }
                }
            }
        }
    }
    return maxSquare;
}
int main() {
	int r,c;
	cin>>r>>c;
	vector<vector<int>> M;
	M.assign(r,vector<int>());
	for(int i=0;i<r;i++){
	    M[i].assign(c,0);
	}
	// Input can be given as whole matrix
	int noOfOnes;
	cin>>noOfOnes;
	for(int i=0;i<noOfOnes;i++){
	    int x,y;
	    cin>>x>>y;
	    M[x][y]=1;
	}
	cout<<largestSquare(M,r,c)<<endl;
}
/*
Input:
4 5
14
0 0
0 1
0 3
1 1
1 2
1 3
2 0
2 1
2 2
2 3
3 1
3 2
3 3
3 4
*/