#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int u[500000],cycle[500000];
int find(int x){
    if(u[x]<0)return x;
    else return u[x]=find(u[x]);
}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b) return false;
    u[a]+=u[b],cycle[a]|=cycle[b],u[b]=a;
    return true;
}

int main() {
    memset(u,-1,sizeof(u));
    int n;scanf("%d",&n);
    vector<pll> v(n);
    vector<ll> numbering;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll a,b;scanf("%lld %lld",&a,&b);
        v[i]={a,b};
        numbering.push_back(a),numbering.push_back(b);
        ans+=a+b;
    }
    sort(numbering.begin(),numbering.end());
    numbering.erase(unique(numbering.begin(),numbering.end()),numbering.end());
    for(auto i:numbering)ans-=i;
    for(auto [a,b]:v){
        int x=lower_bound(numbering.begin(),numbering.end(),a)-numbering.begin(),
        y=lower_bound(numbering.begin(),numbering.end(),b)-numbering.begin();
        if(!merge(x,y))cycle[find(x)]=cycle[find(y)]=1;
    }
    map<ll,ll> ma;
    for(auto [a,b]:v){
        int x=lower_bound(numbering.begin(),numbering.end(),a)-numbering.begin();
        if(!cycle[find(x)])ma[find(x)]=max(ma[find(x)],max(a,b));
    }
    for(auto i:ma)ans+=i.second;
    printf("%lld",ans);
    return 0;
}