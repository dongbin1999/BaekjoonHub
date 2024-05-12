#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll,3> tup;

int u[300001];
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return 0;
    if(-u[x]<-u[y])swap(x,y);
    u[x]+=u[y],u[y]=x;
    return 1;
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<tup> e(m);
    for(auto &[x,y,z]:e)scanf("%lld%lld%lld",&x,&y,&z);
    ll ans=(1ll<<60)-1;
    for(ll i=1ll<<59;i;i>>=1){
        memset(u,-1,sizeof(u));
        for(auto [x,y,z]:e)if(((ans^i)&z)==z)merge(x,y);
        if(find(1)==find(n))ans^=i;
    }
    printf("%lld",ans);
}