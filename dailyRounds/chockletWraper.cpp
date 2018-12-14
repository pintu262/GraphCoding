#include <bits/stdc++.h>
using namespace std;

int main() {
    int money,price,wrap,moreChoc=0;
    cin>>money>>price>>wrap;
    int n= money/price;
    int totalCho=n;
    int rem=money%price;
    while(n>=wrap){
        rem =rem + (n%wrap);
        n=n/wrap;
        totalCho+=n;
        if(rem%wrap==0 && rem !=0){
            moreChoc=(rem/wrap);
            totalCho += moreChoc;
            n+=moreChoc;
            rem=0;
        }
    }
    cout<<totalCho<<endl;
}
