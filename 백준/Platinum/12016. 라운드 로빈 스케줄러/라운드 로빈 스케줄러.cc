#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int sz=1<<17;
ll arr[sz*2];

void update(int i,ll val){
    i+=sz,arr[i]+=val;
    while(i>1)i/=2,arr[i]=arr[i*2]+arr[i*2+1];
}

ll query(int s,int e,int node,int ns,int ne){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)/2;
    return query(s,e,node*2,ns,mid)+query(s,e,node*2+1,mid+1,ne);
}ll query(int s,int e){return query(s,e,1,0,sz-1);}

int main(){
    int n;scanf("%d",&n);
    vector<pll> v(n+1);
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i].first);
        v[i].second=i;
    }
    sort(v.begin(),v.end());
    vector<pll> ans;
    ans.push_back({v[1].second,(v[1].first-1)*(ll)n+v[1].second});
    update(v[1].second,1);
    for(int i=2;i<=n;i++){
        ll dist,add=v[i].first-v[i-1].first;
        if(v[i].second>v[i-1].second)
            dist=v[i].second-v[i-1].second-query(v[i-1].second+1,v[i].second-1);
        else dist=v[i].second-v[i-1].second+1+query(v[i].second+1,v[i-1].second-1);
        ans.push_back({v[i].second,ans.back().second+add*(n-query(1,sz-1))+dist});
        update(v[i].second,1);
    }
    sort(ans.begin(),ans.end());
    for(auto i:ans)printf("%lld\n",i.second);
    return 0;
}