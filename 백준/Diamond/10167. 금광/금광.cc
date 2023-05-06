#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> plll;
#define UNIQUE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
const int sz=1<<13;
struct element{
    ll l_x,x_r,x_x,sum;
};
element arr[sz*2];
vector<ll> vx,vy;
plll p[3002];

ll rex(ll x){return lower_bound(vx.begin(),vx.end(),x)-vx.begin();}
ll rey(ll x){return lower_bound(vy.begin(),vy.end(),x)-vy.begin();}

void update(ll i,ll x){
    i+=sz,arr[i].l_x+=x,arr[i].x_r+=x,arr[i].x_x+=x,arr[i].sum+=x;
    while(i>1){
        i/=2;
        arr[i].l_x=max(arr[i*2].l_x,arr[i*2].sum+arr[i*2+1].l_x);
        arr[i].x_r=max(arr[i*2].x_r+arr[i*2+1].sum,arr[i*2+1].x_r);
        arr[i].x_x=max(max(arr[i*2].x_x,arr[i*2+1].x_x),arr[i*2].x_r+arr[i*2+1].l_x);
        arr[i].sum=arr[i*2].sum+arr[i*2+1].sum;
    }
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        ll x,y,w;scanf("%lld %lld %lld",&x,&y,&w);
        vx.push_back(x),vy.push_back(y);
        p[i]={{x,y},w};
    }
    UNIQUE(vx);UNIQUE(vy);
    vector<vector<pll>> v(vx.size());
    for(int i=1;i<=n;i++)v[rex(p[i].first.first)].push_back({rey(p[i].first.second),p[i].second});
    sort(p+1,p+1+n);
    
    ll ans=0;
    for(int i=0;i<vx.size();i++){
        memset(arr,0,sizeof(arr));
        for(int j=i;j<vx.size();j++){
            for(auto k:v[j])update(k.first,k.second);
            ans=max(ans,arr[1].x_x);
        }
    }
    printf("%lld",ans);
    return 0;
}