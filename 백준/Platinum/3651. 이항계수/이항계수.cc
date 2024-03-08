#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());

int main(){
    ll m;scanf("%lld",&m);
    vector<pll> v;
    for(ll k=1;k<=min(100ll,m);k++){
        ll l=k,r=m,mid;
        while(l<=r){
            mid=l+r>>1;
            bool over=false;
            __int128 c=1;
            for(ll i=1;i<=k;i++){
                c=c*(mid+1-i)/i;
                if(c>m){over=1;break;}
                if(c==m)v.push_back({mid,i});
            }
            if(!over)l=mid+1;
            else r=mid-1;
        }
    }
    for(int i=0,n=v.size();i<n;i++)v.push_back({v[i].first,v[i].first-v[i].second});
    UNIQUE(v);
    printf("%d\n",v.size());
    for(auto [x,y]:v)printf("%lld %lld\n",x,y);
}