#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,ll,ll> tup;

vector<int> tree[200001];
ll x[200001],ans=-2e18;
tup go(int node=1){
    ll sum=x[node],team=x[node],sum2=-2e18;
    vector<ll> one;
    for(auto nx:tree[node]){
        auto [a,b,c]=go(nx);
        sum+=a;
        sum2=max(sum2,a>0?c:b);
        team=max(team,b);
        one.push_back(b);
    }
    if(one.size()>=2){
        sort(one.begin(),one.end(),greater<ll>());
        ans=max(ans,one[0]+one[1]);
    }
    ans=max(ans,sum+sum2);
    return {max(0ll,sum),max(team,sum),sum2};
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int pa;scanf("%lld%d",&x[i],&pa);
        if(pa!=-1)tree[pa].push_back(i);
    }
    go();
    printf("%lld",ans);
    return 0;
}