#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
pll go[4]={{0,1},{0,-1},{1,0},{-1,0}};

unordered_set<ll> se;
ll f(ll x,ll y){
    return (x+3e5)*mod+(y+3e5);
}
pll rev(ll v){
    int x=v/mod,y=v%mod;
    return {x-3e5,y-3e5};
}

int main(){
    ll x,y,t,r,c,n;scanf("%lld%lld%lld%lld%lld%lld",&x,&y,&t,&r,&c,&n);
    while(n--){
        ll xx,yy;scanf("%lld%lld",&xx,&yy);
        se.insert(f(xx,yy));
    }
    unordered_map<ll,ll> ma;
    ma[f(x,y)]=1;
    ll ans=pll{x,y}==pll{r,c};
    while(t--){
        unordered_map<ll,ll> nma;
        for(auto [xy,cnt]:ma){
            x=rev(xy).first,y=rev(xy).second;
            for(auto [dx,dy]:go){
                ll nx=x+dx,ny=y+dy;
                ll nf=f(nx,ny);
                if(se.count(nf)||abs(nx-r)+abs(ny-c)>t)continue;
                nma[nf]=(nma[nf]+cnt)%mod;
            }
        }
        ma=nma;
        for(auto [xy,cnt]:ma)
            if(xy==f(r,c))ans=(ans+cnt)%mod;
        if(ma.count(f(r,c)))ma.erase(ma.find(f(r,c)));
    }
    printf("%lld",ans);
}