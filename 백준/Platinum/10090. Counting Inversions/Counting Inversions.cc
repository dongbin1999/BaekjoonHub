#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int sz=1<<20;
ll arr[sz*2];
void update(int i){
    i+=sz,arr[i]++;
    while(i>1)i/=2,arr[i]=arr[i*2]+arr[i*2+1];
}
ll query(int s,int e,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)/2;
    return query(s,e,node*2,ns,mid)+query(s,e,node*2+1,mid+1,ne);
}
int main(){
    int n;scanf("%d",&n);
    vector<pll> v(n);int idx=0;
    for(auto &[x,y]:v)scanf("%lld",&x),y=idx++;
    ll ans=0;
    sort(v.begin(),v.end(),greater<pll>());
    for(auto [x,y]:v)
        update(y),ans+=query(0,y-1);
    printf("%lld",ans);
    return 0;
}