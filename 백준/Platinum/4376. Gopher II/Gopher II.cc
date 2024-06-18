#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int a[101],b[101],vis[101];
vector<int> graph[101];
pll g[101],h[101];

bool BM(int cur){
    vis[cur]=1;
    for(int go:graph[cur])
        if(b[go]==-1||!vis[b[go]]&&BM(b[go])){
            a[cur]=go,b[go]=cur;
            return 1;
        }
    return 0;
}

int main(){
    int n,m,s,v;
    while(scanf("%d%d%d%d",&n,&m,&s,&v)!=EOF){
        fill(a+1,a+1+n,-1),fill(b+1,b+1+m,-1);
        ll len=s*v*s*v;
        for(int i=1;i<=n;i++){
            ll x1,x2,y1,y2;scanf("%lld.%lld %lld.%lld",&x1,&x2,&y1,&y2);
            g[i]={x1*10+x2,y1*10+y2};
        }
        for(int i=1;i<=m;i++){
            ll x1,x2,y1,y2;scanf("%lld.%lld %lld.%lld",&x1,&x2,&y1,&y2);
            h[i]={x1*10+x2,y1*10+y2};
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
                auto [gx,gy]=g[i];auto[hx,hy]=h[j];
                if((gx-hx)*(gx-hx)+(gy-hy)*(gy-hy)<=len*100)graph[i].push_back(j);
            }
        int ans=0;
        for(int i=1;i<=n;i++){
            fill(vis+1,vis+1+n,false);
            ans+=BM(i);
        }
        printf("%d\n",n-ans);
        for(int i=1;i<=n;i++)graph[i].clear();
    }
    return 0;
}