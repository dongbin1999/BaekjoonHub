#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

pll operator-(pll a,pll b){return {a.first-b.first,a.second-b.second};}

ll ccw(pll a,pll b,pll c){
    ll x[3]={a.first,b.first,c.first},y[3]={a.second,b.second,c.second};
    return x[0]*y[1]+x[1]*y[2]+x[2]*y[0]-(y[0]*x[1]+y[1]*x[2]+y[2]*x[0]);
}
ll ccw(pll a,pll b){
    return a.first*b.second-b.first*a.second;
}
ll dist(pll a,pll b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
vector<pll> convex_hull(vector<pll> v){
    vector<pll> ret;
    swap(v[0],*min_element(v.begin(),v.end()));
    sort(v.begin()+1,v.end(),[&](pll a,pll b){
        ll cw=ccw(v[0],a,b);
        if(cw)return cw>0;
        return dist(v[0],a)<dist(v[0],b);
    });
    for(auto i:v){
        while(ret.size()>=2&&ccw(ret[ret.size()-2],ret.back(),i)<=0)ret.pop_back();
        ret.push_back(i);
    }
    return ret;
}

ll far(vector<pll> init,vector<pll> &d,ll day){
    vector<pll> v(init.size());
    for(int i=0;i<init.size();i++)
        v[i]={day*d[i].first+init[i].first,day*d[i].second+init[i].second};
    vector<pll> ch=convex_hull(v);
    int n=ch.size();
    ll ret=0;
    int a=min_element(ch.begin(),ch.end())-ch.begin(),b=max_element(ch.begin(),ch.end())-ch.begin();
    for(int i=0;i<n;i++){
        ret=max(ret,dist(ch[a],ch[b]));
        pll v1=ch[a]-ch[(a+1)%n],v2=ch[b]-ch[(b+1)%n];
        ccw(v1,v2)>0?b=(b+1)%n:a=(a+1)%n;
    }
    return ret;
}

int main(){
    int n,t;scanf("%d%d",&n,&t);
    vector<pll> v(n),d(n);
    for(int i=0;i<n;i++)scanf("%lld%lld%lld%lld",&v[i].first,&v[i].second,&d[i].first,&d[i].second);

    ll l=0,r=t,lmid,rmid;
    while(l+3<r){
        lmid=(l+l+r)/3,rmid=(l+r+r)/3;
        if(far(v,d,lmid)>far(v,d,rmid))l=lmid;
        else r=rmid;
    }
    pll ans={2e18,2e18};
    for(ll i=l;i<=r;i++)ans=min(ans,{far(v,d,i),i});
    printf("%lld\n%lld",ans.second,ans.first);
    return 0;
}
