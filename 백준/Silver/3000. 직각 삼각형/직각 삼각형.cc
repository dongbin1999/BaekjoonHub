#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n;scanf("%d",&n);
    vector<pii> v(n);
    map<ll,ll> mx,my;
    for(auto &[x,y]:v)scanf("%d%d",&x,&y),mx[x]++,my[y]++;
    ll ans=0;
    for(auto [x,y]:v)ans+=(mx[x]-1)*(my[y]-1);
    printf("%lld",ans);
}