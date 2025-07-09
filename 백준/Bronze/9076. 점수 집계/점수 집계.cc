#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    while(n--){
        deque<int> dq(5);
        for(auto &x:dq)cin>>x;
        sort(dq.begin(),dq.end());
        dq.pop_back(),dq.pop_front();
        if(dq.back()-dq.front()>=4)cout<<"KIN\n";
        else cout<<(accumulate(dq.begin(),dq.end(),0))<<'\n';
    }
}