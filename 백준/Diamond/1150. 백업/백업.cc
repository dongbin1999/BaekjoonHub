#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int u[100001];
pll lr[100001];
ll c[100001];
int find(int x){
    if(u[x]<0)return x;
    return u[x]=find(u[x]);
}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return false;
    lr[a]={min(lr[a].first,lr[b].first),max(lr[a].second,lr[b].second)};
    u[a]+=u[b],c[a]+=c[b],u[b]=a;
    return true;
}

int main() {
    memset(u,-1,sizeof(u));
    int n,k;scanf("%d%d",&n,&k);
    vector<ll> v(n);
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    for(int i=0;i<n;i++){
        scanf("%lld",&v[i]);
        if(i)c[i]=v[i]-v[i-1],pq.push({c[i],i}),lr[i]={i,i};
    }
    ll ans=0;
    while(!pq.empty()){
        auto [cost,idx]=pq.top();pq.pop();
        idx=find(idx);
        auto [l,r]=lr[idx];
        if(c[idx]!=cost||l<1||r>=n)continue;
        ans+=cost,k--;if(!k)break;
        merge(idx,l-1),merge(idx,r+1);
        c[idx]-=cost*2;
        pq.push({c[idx],idx});
    }
    printf("%lld",ans);
}