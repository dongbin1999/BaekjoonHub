#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll g;scanf("%lld",&g);
    vector<ll> ans;
    for(ll i=1;i*i<=g;i++){
        if(g%i)continue;
        ll pl=g/i,mi=i;
        ll x=(pl+mi)/2,y=(pl-mi)/2;
        if(x<1||y<1||x*x-y*y!=g)continue;
        ans.push_back(x);
    }
    sort(ans.begin(),ans.end());
    if(ans.empty())printf("-1");
    else for(auto i:ans)printf("%lld\n",i);
    return 0;
}