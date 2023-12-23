#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int u[100001];
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return false;
    u[a]+=u[b],u[b]=a;
    return true;
}

int main(){
    int n;scanf("%d",&n);
    memset(u,-1,sizeof(u));
    vector<tuple<ll,int,int>> v;
    for(int i=1;i<n;i++){
        int x,y;ll w;scanf("%d%d%lld",&x,&y,&w);
        v.push_back({w,x,y});
    }
    sort(v.begin(),v.end(),greater<tuple<ll,int,int>>());
    ll ans=0;
    for(auto [w,x,y]:v){
        int a=-u[find(x)],b=-u[find(y)];
        ans+=w*a*b;
        merge(x,y);
    }
    printf("%lld",ans);
}