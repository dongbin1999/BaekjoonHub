#include<bits/stdc++.h>
using namespace std;

int d[101][101],cost[101],u[101];
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return 0;
    u[a]+=u[b],cost[a]=cost[b]=min(cost[a],cost[b]),u[b]=a;
    return 1;
}

int main(){
    int n;scanf("%d",&n);
    memset(d,0x3f,sizeof(d));
    memset(u,-1,sizeof(u));
    for(int i=1;i<=n;i++)scanf("%d",&cost[i]);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        int x;scanf("%1d",&x);
        if(x)d[i][j]=1;
    }
    for(int via=1;via<=n;via++)for(int s=1;s<=n;s++)for(int e=1;e<=n;e++)
        d[s][e]=min(d[s][e],d[s][via]+d[via][e]);
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
        if(d[i][j]<1e9&&d[j][i]<1e9)merge(i,j);
    int ans=0;
    for(int i=1;i<=n;i++)if(find(i)==i)ans+=cost[i];
    printf("%d",ans);
}