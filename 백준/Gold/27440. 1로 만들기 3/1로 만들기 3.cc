#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
map<ll,ll> ma;

int main(){
    ll n;scanf("%lld",&n);
    priority_queue<pll,vector<pll>,greater<pll>> q;q.push({1,n});ma[n]=1;
    while(!q.empty()){
        pll cur=q.top();q.pop();
        if(!ma[cur.second/3]||ma[cur.second/3]>cur.first+1+cur.second%3)
            ma[cur.second/3]=cur.first+1+cur.second%3,q.push({ma[cur.second/3],cur.second/3});
        if(!ma[cur.second/2]||ma[cur.second/2]>cur.first+1+cur.second%2)
            ma[cur.second/2]=cur.first+1+cur.second%2,q.push({ma[cur.second/2],cur.second/2});
    }
    printf("%lld",ma[1]-1);
    return 0;
}