#include <bits/stdc++.h>
using namespace std;
/*
Suppose there is infinite size of chess board, you have given two Bishop(Who move only diagonally), You need to find the minimum number of moves so that they
cross each other or met.
*/
bool isInSameColor(int B1x,int B1y,int B2x,int B2y){
    if(((B1x+B1y)%2)==((B2x+B2y)%2)){
        return true;
    }
    return false;
}
bool isInDiagonal(int B1x,int B1y,int B2x,int B2y){
    if(abs(B1x-B2x)==abs(B1y-B2y)){
        return true;
    }
    return false;
}
int getMinStepsToMet(int B1x,int B1y,int B2x,int B2y){
    if(isInSameColor(B1x,B1y,B2x,B2y)){
        if(isInDiagonal(B1x,B1y,B2x,B2y)){
            return 1;
        }else{
            return 2;
        }
    }else{
        return -1;
    }
}
int main() {
    int B1x,B1y,B2x,B2y;
    cin>>B1x>>B1y;
    cin>>B2x>>B2y;
    int steps = getMinStepsToMet(B1x,B1y,B2x,B2y);
    if(steps!=-1){
        cout<<"Minimum Number of Steps ="<<steps<<endl;
    }else{
        cout<<"They Will never met"<<endl;
    }
}
/*
Input:
1 2
10 21
Output:
Minimum Number of Steps =2
*/