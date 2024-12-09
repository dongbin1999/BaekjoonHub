#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef array<ll,3> vec;
const int sz=1<<17;
struct element{
    ll l_x,x_r,x_x,sum;
};
element arr[sz*2];
ll l[100001],r[100001],mid[100001],ans[100001];
pll h[100002];

void update(ll i){
    i+=sz,arr[i].l_x=arr[i].x_r=arr[i].x_x=arr[i].sum=1;
    while(i>1){
        i/=2;
        arr[i].l_x=max(arr[i*2].l_x,arr[i*2].sum+arr[i*2+1].l_x);
        arr[i].x_r=max(arr[i*2].x_r+arr[i*2+1].sum,arr[i*2+1].x_r);
        arr[i].x_x=max(max(arr[i*2].x_x,arr[i*2+1].x_x),arr[i*2].x_r+arr[i*2+1].l_x);
        arr[i].sum=arr[i*2].sum+arr[i*2+1].sum;
    }
}

vector<pll> seg;
void query(ll s,ll e,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return;
    if(s<=ns&&ne<=e){seg.push_back({ns,node});return;}
    int m=(ns+ne)>>1;
    query(s,e,node<<1,ns,m),query(s,e,node<<1|1,m+1,ne);
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&h[i].first),h[i].second=i;
    sort(h+1,h+1+n,greater<pll>()),h[n+1].first=-1;
    int q;scanf("%d",&q);
    for(int i=0;i<q;i++)l[i]=1,r[i]=1e9;
    vector<vec> Q(q);
    for(auto &[L,R,w]:Q)scanf("%lld%lld%lld",&L,&R,&w);
    int it=35;
    while(it--){
        for(int i=0;i<sz*2;i++)arr[i]={INT_MIN,INT_MIN,INT_MIN,INT_MIN};
        vector<pll> H;
        for(int i=0;i<q;i++)mid[i]=(l[i]+r[i])/2,H.push_back({mid[i],i});
        sort(H.begin(),H.end(),greater<pll>());
        int cur=1;
        for(auto [height,qidx]:H){
            while(h[cur].first>=height)update(h[cur++].second);
            auto [ql,qr,qw]=Q[qidx];
            //printf("[%lld %lld %lld %lld %lld]\n",height,qidx,ql,qr,qw);
            ll W=0;seg.clear(),query(ql,qr);
            sort(seg.begin(),seg.end());
            ll x_r=0;
            for(auto [_,node]:seg){
                W=max({W,arr[node].x_x,x_r+arr[node].l_x});
                x_r=max(x_r+arr[node].sum,arr[node].x_r);
            }
            reverse(seg.begin(),seg.end());
            ll l_x=0;
            for(auto [_,node]:seg){
                W=max({W,arr[node].x_x,l_x+arr[node].x_r});
                l_x=max(l_x+arr[node].sum,arr[node].l_x);
            }
            if(W>=qw)ans[qidx]=max(ans[qidx],mid[qidx]),l[qidx]=mid[qidx]+1;
            else r[qidx]=mid[qidx]-1;
        }
    }
    for(int i=0;i<q;i++)printf("%lld\n",ans[i]);
    return 0;
}