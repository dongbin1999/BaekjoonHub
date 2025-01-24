#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll x,q;scanf("%lld%lld",&x,&q);
    vector<ll> ans;
    ll d=1,sz=0;
    while(1){
        x=x/d*d+d;
        ans.push_back(x),sz++,d++;
        if(sz>1&&ans[sz-1]/sz==ans[sz-2]/(sz-1))break;
    }
    while(q--){
        ll a;scanf("%lld",&a);
        if(sz>=a)printf("%lld\n",ans[a-1]);
        else printf("%lld\n",ans.back()/sz*a);
    }
    return 0;
}