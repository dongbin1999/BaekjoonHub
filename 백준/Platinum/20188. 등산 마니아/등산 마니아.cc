#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,n;
vector<int> tree[300001];
ll go(int node=1,int pa=-1,ll d=0){
    ans+=d*(n-1);
    vector<ll> child;ll sum=0;
    for(auto nx:tree[node]){
        if(nx!=pa){
            child.push_back(go(nx,node,d+1));
            sum+=child.back();
        }
    }
    ll sub=sum;
    for(auto i:child)sum-=i,sub+=sum*i;
    ans-=d*sub;
    return accumulate(child.begin(),child.end(),1ll);
}


int main() {
    scanf("%lld",&n);
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    go();
    printf("%lld",ans);
}