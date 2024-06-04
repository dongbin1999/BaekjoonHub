#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> graph[1001];

//bellman-ford
bool is_cycle(int n,int money){
    vector<int> dist(n+1,-1e9);dist[0]=money;
    int loop=n;
    while(loop--)
        for(int s=0;s<=n;s++)
            for(auto[e,cost]:graph[s])
                if(dist[s]>=cost)
                    dist[e]=max(dist[e],dist[s]-cost);
    vector<int> cmp=dist;
    for(int s=0;s<=n;s++)
        for(auto[e,cost]:graph[s])
            if(dist[s]>=cost)
                dist[e]=max(dist[e],dist[s]-cost);
    for(int i=0;i<=n;i++)if(dist[i]>cmp[i])return true;
    return false;
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    while(m--){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        if(a==1)graph[0].push_back({c,b});
        else if(a==2)graph[b].push_back({0,-c});
        else if(a==3)graph[b].push_back({c,0});
        else{
            int d;scanf("%d",&d);
            if(a==4)graph[b].push_back({d,c});
            else if(a==5)graph[b].push_back({c,-d});
        }
    }
    int l=0,r=2e7,mid,ans=r;
    while(l<=r){
        mid=l+r>>1;
        if(is_cycle(n,mid))ans=min(ans,mid),r=mid-1;
        else l=mid+1;
    }
    if(ans>1e7)printf("INF");
    else printf("%d",ans);
}