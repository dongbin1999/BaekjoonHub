#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int out[1000001],in[1000001],clen[1000001],vis[1000001];

void go(int s){
    vis[s]=1;
    vector<int> v={s};
    while(1){
        int nx=out[s];
        if(vis[nx])break;
        v.push_back(nx),s=nx,vis[s]=1;
    }
    for(auto i:v)clen[i]=v.size();
}

int main(){
    int n,m;scanf("%d%d",&m,&n);
    memset(clen,-1,sizeof(clen));
    memset(out,-1,sizeof(out));
    vector<pii> v;
    while(m--){
        int s,e;scanf("%d%d",&s,&e);
        out[s]=e,in[e]++;
        v.push_back({s,e});
    }
    int ans=0;
    queue<pii> q;
    for(int i=0;i<n;i++)if(!in[i])q.push({i,1});
    while(!q.empty()){
        auto [cur,len]=q.front();q.pop();
        vis[cur]=1;
        int nx=out[cur];
        if(nx!=-1){
            in[nx]--;
            if(in[nx]==0)q.push({nx,len+1});
        }
    }

    for(int i=0;i<n;i++)if(!vis[i])go(i),ans=max(ans,clen[i]);


    for(auto [s,e]:v)in[e]++;
    for(int i=0;i<n;i++)if(!in[i])q.push({i,1});
    while(!q.empty()){
        auto [cur,len]=q.front();q.pop();
        vis[cur]=1;
        ans=max(ans,len);
        int nx=out[cur];
        if(nx!=-1){
            in[nx]--;
            if(in[nx]==0)q.push({nx,len+1});
            if(clen[nx]!=-1)ans=max(ans,clen[nx]+len);
        }
    }

    printf("%d",ans);
}