#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;scanf("%d",&n);
    vector<ll> v(n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]);
    vector<ll> a,b;
    for(int i=0;i<1<<(n/2);i++){
        ll sum=0;
        for(int j=0;j<15;j++)if(i>>j&1)sum+=v[j];
        a.push_back(sum);
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<1<<((n+1)/2);i++){
        ll sum=0;
        for(int j=0;j<15;j++)if(i>>j&1)sum+=v[j];
        b.push_back(sum);
    }
    ll answer=0;
    for(int j=0;j<40;j++){
        vector<ll> aa,bb;
        for(auto i:a)aa.push_back(i%(2ll<<j));
        for(auto i:b)bb.push_back(i%(2ll<<j));
        sort(aa.begin(),aa.end());sort(bb.begin(),bb.end());
        ll cnt=0;
        for(auto i:aa){
            ll x=((1ll<<j)*3ll-i)%(2ll<<j),y=(2ll<<j)-i-1;
            ll l=lower_bound(bb.begin(),bb.end(),x)-bb.begin(),
            r=upper_bound(bb.begin(),bb.end(),y)-bb.begin()-1;
            if(x<=y)cnt+=r-l+1;
            else cnt+=(ll)bb.size()-l + r+1;
        }
        if(cnt&1)answer+=1ll<<j;
    }
    printf("%lld",answer);
    return 0;
}