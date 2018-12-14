#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,c,f,nn,num,sqRootNumOne,v,i=0;
    bool invalid=false;
    cin>>n>>c;
    sqRootNumOne = sqrt(1+(8*n));
    num = (sqRootNumOne -1)/2;
    num=num+1;
    f=num;
    nn=num;
    while(f<=n){
        cout<<f<<endl;
        cout.flush();
        cin>>v;
        if(v==0){
            f=f+(--nn);
        }else if(v==1){
            f = f - (nn)+1;
            cout<<2<<endl;
            break;
        }else if(v==-1){
            invalid=true;
        }
    }
    if(invalid){
        return 0;
    }
    bool brk=false;
    for(i=f;i<=(f+nn)&&(i<=n);i++){
        cout<<i<<endl;
        cin>>v;
        if(v==1){
            brk=true;
            break;
        }
        
    }
    if(i>=n){
        i=n;
    }
    if(brk){
        cout<<3<<" "<<i-1<<endl;
        // cout.flush();
    }else{
        cout<<3<<" "<<i<<endl;
        // cout.flush();
    }
}
