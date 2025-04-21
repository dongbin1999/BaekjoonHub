#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> tree[1000001];
int u[1000001];
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return 0;
    u[a]+=u[b],u[b]=a;
    return 1;
}
vector<int> ans;
int go(int cur,int pa=-1){
    int ret=0,edge=-1;
    for(auto [nx,e]:tree[cur]){
        if(nx==pa){edge=e;continue;}
        ret+=go(nx,cur);
    }
    if(ret%2==0)ret++,ans.push_back(edge);
    else ret=0;
    return ret;
}
int main(){
    memset(u,-1,sizeof(u));
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;scanf("%d%d",&x,&y);
        if(merge(x,y))tree[x].push_back({y,i}),tree[y].push_back({x,i});
    }
    ans.clear();
    for(int i=1;i<=n;i++){
        if(u[i]>0)continue;
        if(u[i]%2)return !printf("-1");
        go(i);
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(auto x:ans)printf("%d ",x);
}