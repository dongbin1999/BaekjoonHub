#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());

bool chk(ll p,vector<ll> &a){
    set<ll> se;
    for(auto i:a){
        se.insert(i%p);
        if(se.size()>3)return false;
    }
    return true;
}

int main(){
    int n;scanf("%d",&n);
    vector<ll> a(n);
    ll mx=2e11;
    for(int i=0;i<n;i++)scanf("%lld",&a[i]),mx=min(mx,a[i]/4);
    UNIQUE(a);n=a.size();
    if(n<=3)return !printf("%lld",mx*(mx+1)/2);
    vector<ll> ans;
    for(int i=0;i<4;i++)for(int j=i+1;j<4;j++){
        ll d=a[j]-a[i];
        for(ll p=1;p*p<=d;p++){
            if(d%p!=0)continue;
            if(p<=mx&&chk(p,a))ans.push_back(p);
            if(d/p<=mx&&d/p!=p&&chk(d/p,a))ans.push_back(d/p);
        }
    }
    UNIQUE(ans);
    printf("%lld",accumulate(ans.begin(),ans.end(),0ll));
}