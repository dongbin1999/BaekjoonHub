#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll,3> tup;

int main() {
    int n;scanf("%d",&n);
    vector<ll> v(n+n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]),v[i+n]=v[i];
    ll l=1,r=1e15,mid,ans=1;
    while(l<=r){
        mid=(l+r)/2;
        vector<tup> idx;
        ll x=0;ll pre=0;
        for(int i=0;i<n;i++){
            x+=v[i];
            if(x>=mid)idx.push_back({pre,i,x}),x=0,pre=i+1;
        }
        bool ok=idx.size()>=3;
        if(idx.size()<=1){r=mid-1;continue;}

        idx.push_back({pre,n-1,x});
        while(idx[0][0]<n){
            auto &[fl,fr,fx]=idx[0];
            auto &[sl,sr,sx]=idx[1];
            auto &[tl,tr,tx]=idx[2];
            fx-=v[fl++];
            while(fr+1<v.size()&&fx<mid)fx+=v[++fr];
            while(fr>=sl)sx-=v[sl++];
            while(sr+1<v.size()&&sx<mid)sx+=v[++sr];
            while(sr>=tl)tx-=v[tl++];
            while(tr+1<v.size()&&tx<mid)tx+=v[++tr];
            if(fx>=mid&&sx>=mid&&tx>=mid&&tr-fl<n){ok=1;break;}
        }

        if(ok)ans=max(ans,mid),l=mid+1;
        else r=mid-1;
    }
    printf("%lld",ans);
}