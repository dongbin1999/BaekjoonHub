#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    priority_queue<ll> pq;
    priority_queue<ll,vector<ll>,greater<ll>> pq2;
    int n;scanf("%d",&n);
    ll x=0,y=0,z=0;
    while(n--){
        ll a,b;scanf("%lld%lld",&a,&b);
        x+=abs(a);
        pq2.push(b),z+=b;
        while(pq2.size()>pq.size())z-=pq2.top(),y+=pq2.top(),pq.push(pq2.top()),pq2.pop();
        if(!pq2.empty()&&!pq.empty())
            while(pq2.top()<pq.top()){
                ll t1=pq2.top(),t2=pq.top();
                pq2.pop(),pq.pop();
                pq.push(t1),pq2.push(t2);
                y+=t1-t2,z+=t2-t1;
            }
        ll v=pq.top();
        printf("%lld %lld\n",pq.top(),x+v*(ll)pq.size()-y+z-v*(ll)pq2.size());
    }
}