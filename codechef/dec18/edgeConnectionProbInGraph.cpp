#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int main() {
    int N;
    cin>>N;
    int tot = ((N-1)*(N-2))/2;
    int pp = pow(2,tot);
    pp=pp%mod;
    int arr[N];
    for(int i=0;i<N;i++){
        arr[i]=N-1;
    }
    for(int i=0;i<N-1;i++){
        int u,v;
        cin>>u>>v;
        u=u-1;
        v=v-1;
        arr[u]--;
        arr[v]--;
    }

    for(int i=0;i<N;i++){
        float tt=0.0;
        if(arr[i]>0)
            tt=pow(0.5,arr[i]);
        float num= (tt*pp);
        long nn=(long)num;
        nn = nn%mod;
        cout<<nn<<" ";
    }
    cout<<endl;
}
