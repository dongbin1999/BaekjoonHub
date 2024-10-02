#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
    int n;scanf("%d",&n);
    vector<ll> v(n+1);
    ll sum=0;
    for(int i=1;i<=n;i++)scanf("%lld",&v[i]),sum+=v[i];
    sort(v.begin(),v.end());
    vector<ll> x(n+1);
    for(int i=1;i<=n;i++)x[i]=x[i-1]+v[i];
    pll a={2e18,2e18};
    ll idx=1,cur=1;
    while(1){
        while(idx<v.size()&&cur>=v[idx])idx++;idx--;
        a=min(a,{cur*idx-x[idx]+x[n]-x[idx]-cur*(n-idx),cur});
        cur++;
        if(cur>v.back())break;
    }
    pll ans={2e18,-1};
    for(ll i=1;i<=10000;i++)ans=min(ans,{i*i*n-i*2ll*sum,i});
    printf("%lld %lld",a.second,ans.second);
}