#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<int> tree[100001];
ll ans;
pll a[100001];
int u[100001],vis[100001];
ll mn[100001];
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return 0;
    u[x]+=u[y],mn[x]=min(mn[x],mn[y]),u[y]=x;
    ans=max(ans,mn[x]*-u[x]);
    return 1;
}

int main(){
    memset(u,-1,sizeof(u));
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i].first),a[i].second=i,mn[i]=a[i].first;
    sort(a+1,a+1+n,greater<pll>());
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        tree[x].push_back(y),tree[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        auto [_,x]=a[i];
        ans=max(ans,_);
        vis[x]=1;
        for(auto nx:tree[x])
            if(vis[nx])merge(x,nx);
    }
    printf("%lld",ans);
    return 0;
}