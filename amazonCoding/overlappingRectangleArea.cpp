#include <bits/stdc++.h>
using namespace std;
unsigned int getSecondDist(int x1,int x2,int x4,int x3){
    if(x4>=x2){
        return abs(x2-x3);
    }else if(x4>=x1 && x4<x2){
        return abs(x3-x4);
    }else if(x4<x1){
        return abs(x1-x3);
    }
    return 0;
}
unsigned int getDist(int x1,int x2,int x3,int x4){
    if(x1<=x3 && x3<=x2){
        return getSecondDist(x1,x2,x4,x3);
    }
    if(x1<=x4 && x4<=x2){
        return getSecondDist(x1,x2,x3,x4);
    }
    return 0;
}
unsigned long areaUnderRectangle(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    unsigned int xval=0;
    if(x1>x2){
        xval=getDist(x2,x1,x3,x4);
    }else{
        xval=getDist(x1,x2,x3,x4);
    }
    unsigned int yval=0;
    if(y1>y2){
        yval=getDist(y2,y1,y3,y4);
    }else{
        yval=getDist(y1,y2,y3,y4);
    }
    return (xval*yval);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int x1,x2,x3,x4;
        int y1,y2,y3,y4;
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>x3>>y3;
        cin>>x4>>y4;
        cout<<areaUnderRectangle(x1,y1,x2,y2,x3,y3,x4,y4)<<endl;
    }
}
/*
2
2 1 5 5 3 2 5 7
2 1 5 5 5 4 7 7
*/