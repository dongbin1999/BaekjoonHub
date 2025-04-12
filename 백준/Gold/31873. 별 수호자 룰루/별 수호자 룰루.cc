#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    ll n,k;scanf("%lld%lld",&n,&k);
    vector<vector<ll>> ans(n/k),r(k);
    vector<ll> a(n/k),able(k);
    ll x=1;
    for(int i=0;i<n/k;i++){
        ll sum=0,y=k-1;
        while(y--)ans[i].push_back(x),sum+=x++;
        a[i]=sum%k;
    }
    while(x<=n)r[x%k].push_back(x),able[x%k]++,x++;
    priority_queue<pll> pq;
    for(int i=0;i<k;i++)if(able[i])pq.push({able[i],i});
    for(int i=0;i<n/k;i++){
        ll no=(k-a[i])%k;
        auto [cnt,cmp]=pq.top();pq.pop();
        if(no==cmp){
            if(pq.empty())return !printf("NO");
            auto [ncnt,ncmp]=pq.top();pq.pop();
            pq.push({cnt,cmp}),cnt=ncnt,cmp=ncmp;
        }
        ll val=r[cmp].back();r[cmp].pop_back();
        ans[i].push_back(val);
        if(cnt)pq.push({cnt-1,cmp});
    }
    printf("YES\n");
    for(int i=0;i<n/k;i++){
        for(int j=0;j<k;j++)printf("%lld ",ans[i][j]);
        printf("\n");
    }
}