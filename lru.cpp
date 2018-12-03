#include <bits/stdc++.h>
using namespace std;
bool pageFaultUtil(queue<int> &frame,queue<int> &aux,int pagei,int &noPageFrame,int &maxFrameSize){
    bool found=false;
    while(!frame.empty()){
        if(frame.front() == pagei){
            found=true;
        }else{
            aux.push(frame.front());
        }
            frame.pop();
    }
    if(!found){
        if(noPageFrame<maxFrameSize){
            while(!aux.empty()){
                frame.push(aux.front());aux.pop();
            }
            noPageFrame++;
            cout<<pagei<<" ";
            frame.push(pagei);
        }else if(noPageFrame==maxFrameSize){
            aux.pop();
            while(!aux.empty()){
                frame.push(aux.front());aux.pop();
            }
            cout<<pagei<<" ";
            frame.push(pagei);
        }else{
            cout<<"Error";
            exit(0);
        }
    }else{
        while(!aux.empty()){
            frame.push(aux.front());aux.pop();
        }
        frame.push(pagei);
    }
    return (!found);
}
int pageFault(int page[],int n){
    int pageFaultCount=0;
    queue<int> frame;
    queue<int> aux;
    int maxFrameSize=3;
    int numberOfPagesInFrame=0;
    
    frame.push(page[0]);
    cout<<page[0]<<" ";
    pageFaultCount++;
    numberOfPagesInFrame++;
    
    for(int i=1;i<n;i++){
        if(pageFaultUtil(frame,aux,page[i],numberOfPagesInFrame,maxFrameSize)){
            pageFaultCount++;
        }
    }
    return pageFaultCount;
}
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        int page[n];
        for(int i=0;i<n;i++){
            cin>>page[i];
        }
        int numberOfPageFault= pageFault(page,n);
        cout<<endl;
        cout<<"Number Of PageFault = "<<numberOfPageFault<<endl;
    }
    
}
/*
Input:
first line is number of inputs
then number of pages
then page squence

output:
first line will print the page fault
second line will print the number of pageFault

2
4
1 1 1 1
12
1 2 3 4 1 2 5 1 2 3 4 5

*/
