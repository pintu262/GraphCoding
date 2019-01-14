#include <bits/stdc++.h>
using namespace std;
/*
Machine Coding Question: There is given some set of stock entries, There is sell of stock and Buy of stock. One can only Buy the stock 
at a higher price. 
If stock is not available or not sufficient to fulfill, there will be either no fulfillment or 
there will be partial fulfillment or multiple fulfillment of stock.

Input:
1 09:45 FK Sell 100 240.10
2 09:45 FK Sell 90 237.45
3 09:47 FK Buy 80 238.10
5 09:48 FK Sell 220 241.50
6 09:49 FK Buy 50 238.50
7 09:52 AZ Buy 10 100.10
8 10:01 FK Sell 20 240.10
9 10:02 FK Buy 150 242.70
Output:
2 3 80 237.45
2 6 10 237.45
1 9 100 240.1
8 9 20 240.1
5 9 30 241.5
*/
struct StockObj{
  int order_id;
  string sell_time;
  int quantity;
  double price;
};
long getTime(string sell_time){
    string hr="",mi="";
    for(int i=0;i<sell_time.length();i++){
        if(sell_time[i]==':'){
            hr = sell_time.substr(0,i-1);
            mi = sell_time.substr(i+1,sell_time.length());
            break;
        }
    }
    long t = 0;
    long hrFromStr = stol(hr);
    long minFromStr = stol(mi);
    t += ((hrFromStr*60) + minFromStr);
    return t;
}
struct myComp{
    bool operator()(StockObj const& o1, StockObj const& o2) {
        if(abs(o1.price-o2.price)<0.0001){
            return getTime(o1.sell_time)>getTime(o2.sell_time);
        }
        return o1.price>o2.price;
    }
};

StockObj getStockObj(int id,string _t,int qty,double p){
    StockObj obj ;
    obj.order_id = id;
    obj.sell_time = _t;
    obj.quantity = qty;
    obj.price = p;
    return obj;
}

int main() {
    map<string,priority_queue<StockObj,vector<StockObj>,myComp>> m;
    int id,qty;
    string _time,_buy_or_sell,_stock_name;
    double _price;
    int t=8;// Number of time for the loop to get the input
    while(t--){
        cin>>id;
        cin>>_time;
        cin>>_stock_name;
        cin>>_buy_or_sell;
        cin>>qty;
        cin>>_price;
        if(_buy_or_sell.compare("Sell")==0){
            StockObj temp = getStockObj(id,_time,qty,_price);
            if(m.find("_stock_name")!=m.end()){
                m["_stock_name"].push(temp);
            }else{
                priority_queue<StockObj,vector<StockObj>,myComp> ss;
                ss.push(temp);
                m["_stock_name"]=ss;
            }
        }else{
            
            if(m.find("_stock_name")!=m.end()){
                priority_queue<StockObj,vector<StockObj>,myComp> tempPq = m["_stock_name"];
                queue<StockObj> que;
                int qtyServed = 0;
                int sellOrderId = 0;
                double servePrice = 0.0d;
                while(!tempPq.empty() && qty>0){
                    StockObj sTemp = tempPq.top();tempPq.pop();
                    if(sTemp.price<=_price && getTime(sTemp.sell_time)<=getTime(_time)){
                        
                        if(sTemp.quantity>= qty){
                            qtyServed = qty;
                            sTemp.quantity = sTemp.quantity-qty;
                        }else{
                            qtyServed = sTemp.quantity;
                            qty = qty -sTemp.quantity;
                            sTemp.quantity = 0;
                        }
                        sellOrderId = sTemp.order_id;
                        servePrice = sTemp.price;
                        cout<<sellOrderId<<" "<<id<<" "<<qtyServed<<" "<<servePrice<<endl;
                    }
                    if(sTemp.quantity>0){
                        que.push(sTemp);
                    }
                }
                while(!que.empty()){
                    tempPq.push(que.front());que.pop();
                }
                m["_stock_name"] = tempPq;
            }
        }
    }
}
