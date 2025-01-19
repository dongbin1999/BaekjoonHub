#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int u[1001],v[1001][1001],vis[1002];
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return 0;
    u[a]+=u[b],u[b]=a;
    return 1;
}

int main(){
    int n,m;
    while(1){
        scanf("%d%d",&n,&m);
        if(!n)break;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
            scanf("%d",&v[i][j]);
            if(v[i][j])v[i][j]+=v[i-1][j];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            memset(u,-1,sizeof(u)),memset(vis,0,sizeof(vis));
            vector<pii> vv;
            for(int j=1;j<=m;j++)vv.push_back({v[i][j],j});
            sort(vv.begin(),vv.end(),greater<pii>());
            for(auto [h,idx]:vv){
                vis[idx]=1;
                if(vis[idx-1])merge(idx,idx-1);
                if(vis[idx+1])merge(idx,idx+1);
                ans=max(ans,-u[find(idx)]*h);
            }
        }
        printf("%d\n",ans);
    }
}