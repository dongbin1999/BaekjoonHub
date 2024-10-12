#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> tree[100001];
int pa[100001],ans[100001];

void go(int cur,int p=0){
    pa[cur]=p;
    for(auto [nx,cost]:tree[cur])
        if(nx!=p)go(nx,cur);
}

int main(){
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        tree[a].push_back({b,c}),tree[b].push_back({a,c});
    }
    vector<int> v(n+1);
    int any=-1;
    while(k--){
        int x;scanf("%d",&x);
        v[x]=1,any=x;
    }
    go(any);
    for(int i=1;i<=n;i++){
        if(!v[i])continue;
        int x=i;
        while(x&&!ans[x])ans[x]=1,x=pa[x];
    }
    int cnt=0;
    for(int i=1;i<=n;i++)cnt+=ans[i];
    printf("%d",cnt);
}