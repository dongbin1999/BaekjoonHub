#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int main(){
    int n;scanf("%d",&n);
    deque<pll> dq(n);
    for(auto &[x,y]:dq)scanf("%lld%lld",&x,&y);
    sort(dq.begin(),dq.end(),[](pll a,pll b){return a.second<b.second;});
    ll x=-1;
    while(!dq.empty()){
        if(dq.size()==1){x=max(x,dq.front().second*2);break;}
        ll a=dq.front().first,b=dq.back().first;
        x=max(x,dq.front().second+dq.back().second);
        dq.front().first-=min(a,b),dq.back().first-=min(a,b);
        if(!dq.front().first)dq.pop_front();
        if(!dq.back().first)dq.pop_back();
    }
    printf("%lld",x);
}