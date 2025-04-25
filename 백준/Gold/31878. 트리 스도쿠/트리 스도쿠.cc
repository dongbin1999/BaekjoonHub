#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<int> tree[121212];
int cnt[121212],ans[121212];
vector<pii> v;

void go(int cur,int pa=-1,int d=1){
    cnt[d]++;
    for(auto nx:tree[cur])
        if(nx!=pa)go(nx,cur,d+1);
}
void dfs(int cur,int pa=-1,int d=0){
    ans[cur]=v[cnt[d]++].second;
    for(auto nx:tree[cur])
        if(nx!=pa)dfs(nx,cur,d+1);
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        v.push_back({x,i});
    }
    sort(v.begin(),v.end());
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        tree[x].push_back(y),tree[y].push_back(x);
    }
    go(1);
    for(int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
    dfs(1);
    printf("YES\n");
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}