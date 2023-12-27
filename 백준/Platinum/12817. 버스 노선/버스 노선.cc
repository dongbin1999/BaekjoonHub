#include <bits/stdc++.h>
using namespace std;
vector<int> tree[1000001];
typedef long long ll;

ll n,ans[1000001];
ll go(int node=1,int pa=1){
    vector<ll> v;
    ll ret=1;
    for(auto nx:tree[node])
        if(nx!=pa)v.push_back(go(nx,node)),ret+=v.back();
    v.push_back(n-ret);
    for(auto i:v)ans[node]+=i*(n-i);
    ans[node]+=n-1;
    return ret;
}

int main(){
    scanf("%lld",&n);
    for(ll i=1;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    go();
    for(ll i=1;i<=n;i++)printf("%lld\n",ans[i]);
    return 0;
}