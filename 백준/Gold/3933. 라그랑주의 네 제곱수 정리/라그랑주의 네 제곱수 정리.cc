#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll go(ll x,ll d,ll mx){
    if(!x)return !d;
    ll ret=0,root=sqrt(x);
    if(d==1)return root*root==x&&mx>=root;
    for(ll i=min(root,mx);i>=1;i--)
        ret+=go(x-i*i,d-1,i);
    return ret;
}

int main(){
    while(1){
        ll x;scanf("%lld",&x);
        if(!x)break;
        ll ans=0;
        for(int i=1;i<=4;i++)ans+=go(x,i,sqrt(x));
        printf("%lld\n",ans);
    }
}