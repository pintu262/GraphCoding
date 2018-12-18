#include <bits/stdc++.h>
using namespace std;
int isThreatend(int Kx,int Ky,int Qx,int Qy,int n){// Assuming board start with 0,0 
    if(Kx<0 || Kx>=n || Qx<0 || Qx>=n ||Ky<0 || Ky>=n || Qy<0 || Qy>=n || (Qx==Kx && Qy==Ky)){
        return -1;
    }
    if(Kx==Qx || Ky==Qy || abs(Qx-Kx)==abs(Qy-Ky)){
        return 1;
    }
    return 0;
}
/*
00 01 02 03
10 11 12 13
20 21 22 23
30 31 32 33*/
int main() {
    int Kx,Ky,Qx,Qy;
    int n;
    cin>>n;// n x n chess board
    cin>>Kx>>Ky>>Qx>>Qy;
    int res = isThreatend(Kx,Ky,Qx,Qy,n);
    if(res==-1){
        cout<<"Invalid Position"<<endl;
    }else if(res == 0){
        cout<<"Not Threatend"<<endl;
    }else{
        cout<<"Threatend"<<endl;
    }
}
/*
Input:
8
4 0 7 3
Output:
Threatend
*/