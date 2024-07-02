#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
const ll mod=1e9+7;

ll a[501][501],u[501],c[501]={0,1,1};
ll find(ll x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(ll x,ll y){
    x=find(x),y=find(y);
    if(x==y)return 0;
    if(-u[x]<-u[y])swap(x,y);
    u[x]+=u[y],u[y]=x;
    return 1;
}

int main(){
    memset(u,-1,sizeof(u));
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%lld",&a[i][j]);
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
        if(a[i][j]&&a[j][i])merge(i,j);
    ll ans=1;
    for(int i=2;i<=n;i++)c[i]=c[i-1]*(i-1)%mod;
    for(int i=1;i<=n;i++)if(u[i]<-1)ans=ans*c[-u[i]]%mod;
    for(int i=1;i<=n;i++){
        if(find(i)!=i)continue;
        vector<ll> nx;
        for(int j=1;j<=n;j++){
            if(find(j)!=j)continue;
            if(i==j)continue;
            if(a[i][j])nx.push_back(j);
        }
        UNIQUE(nx);
        if(nx.size()==1)ans=ans*-u[nx.back()]%mod;
    }
    printf("%lld",ans);
}