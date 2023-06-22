#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int sz=1<<17;
pll arr[sz*2],zero;
pll operator+(pll a,pll b){return{a.first+b.first,a.second+b.second};}
void operator+=(pll &a,pll b){a.first+=b.first,a.second+=b.second;}

void update(int i,pll val){
    i+=sz,arr[i]+=val;
    while(i>1)i/=2,arr[i]=arr[i*2]+arr[i*2+1];
}

pll query(int s,int e,int node,int ns,int ne){
    if(e<ns||ne<s)return zero;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)/2;
    return query(s,e,node*2,ns,mid)+query(s,e,node*2+1,mid+1,ne);
}pll query(int s,int e){return query(s,e,1,0,sz-1);}

ll cost(int h){pll f=query(1,h);return f.first*(ll)h+f.second;}

int ternary_search(){
    int l=1,r=1e5,lmid,rmid;
    while(l+3<r){
        lmid=(l+l+r)/3,rmid=(l+r+r)/3;
        if(cost(lmid)<cost(rmid))r=rmid;
        else l=lmid;
    }
    int ret=r;
    for(int i=l;i<r;i++)if(cost(i)<cost(ret))ret=i;
    return ret;
}

int main(){
    int n,k;scanf("%d%d",&n,&k);
    vector<ll> h(n),a(n),b(n);
    for(int i=0;i<n;i++)scanf("%lld",&h[i]);
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    for(int i=0;i<n;i++)scanf("%lld",&b[i]);
    for(int i=0;i<k;i++){
        update(1,{-b[i],b[i]*h[i]});update(h[i]+1,{b[i],-b[i]*h[i]});
        update(h[i]+1,{a[i],-a[i]*h[i]});update(sz-1,{-a[i],a[i]*h[i]});
    }
    ll ans=cost(ternary_search());
    for(int i=k;i<n;i++){
        update(1,{b[i-k],-b[i-k]*h[i-k]});update(h[i-k]+1,{-b[i-k],b[i-k]*h[i-k]});
        update(h[i-k]+1,{-a[i-k],a[i-k]*h[i-k]});update(sz-1,{a[i-k],-a[i-k]*h[i-k]});
        update(1,{-b[i],b[i]*h[i]});update(h[i]+1,{b[i],-b[i]*h[i]});
        update(h[i]+1,{a[i],-a[i]*h[i]});update(sz-1,{-a[i],a[i]*h[i]});
        ans=min(ans,cost(ternary_search()));
    }
    printf("%lld",ans);
    return 0;
}