#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tup;
typedef long long ll;
set<int> se;
ll sum[10001],ans[10001];
int query(int r){
    int l=*se.begin();
    printf("? %d %d\n",l,r);
    fflush(stdout);
    ll v;int lx,rx;
    scanf("%lld%d%d",&v,&lx,&rx);
    v-=-sum[l-1]+sum[r-1],ans[r]=v,sum[r]=sum[r-1]+v;
    if(se.count(lx))se.erase(se.find(lx));
    return v;
}

int main() {
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)se.insert(i);
    for(int i=1;i<=n;i++)query(i);
    printf("!\n");
    for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
    return 0;
}