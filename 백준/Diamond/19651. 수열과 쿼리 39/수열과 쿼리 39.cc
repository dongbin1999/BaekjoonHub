#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int sz=1<<17;
struct element{ll l_x,x_r,x_x,sz;};
ll a[sz],b[sz];
element arr[sz<<1];

void update(ll i,ll x){
    i+=sz,arr[i].sz=1,arr[i].l_x=arr[i].x_r=arr[i].x_x=!x;
    while(i>1){
        i/=2;
        arr[i].l_x=arr[i*2].l_x+(arr[i*2].l_x==arr[i*2].sz?arr[i*2+1].l_x:0);
        arr[i].x_r=arr[i*2+1].x_r+(arr[i*2+1].x_r==arr[i*2+1].sz?arr[i*2].x_r:0);
        arr[i].x_x=max({arr[i*2].x_x,arr[i*2+1].x_x,arr[i*2].x_r+arr[i*2+1].l_x});
        arr[i].sz=arr[i*2].sz+arr[i*2+1].sz;
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
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)b[i]=a[i-1]+a[i+1]-a[i]*2,update(i,b[i]);
    int m;scanf("%d",&m);
    while(m--){
        int q;scanf("%d",&q);
        if(q==1){
            int l,r,x,y;scanf("%d%d%d%d",&l,&r,&x,&y);
            b[l-1]+=x,update(l-1,b[l-1]);
            b[l]+=y-x,update(l,b[l]);
            b[r]+=-x-y*(r-l+1),update(r,b[r]);
            b[r+1]+=x+y*(r-l),update(r+1,b[r+1]);
        }
        else{
            int l,r;scanf("%d%d",&l,&r);
            seg.clear(),query(l+1,r-1);
            sort(seg.begin(),seg.end());
            ll x_r=-1e9,mx=0;
            for(auto [_,node]:seg){
                mx=max({mx,arr[node].x_x,x_r+arr[node].l_x});
                if(x_r<0||arr[node].x_x<arr[node].sz)x_r=arr[node].x_r;
                else x_r+=arr[node].sz;
            }
            printf("%lld\n",mx+2);
        }
    }
    return 0;
}