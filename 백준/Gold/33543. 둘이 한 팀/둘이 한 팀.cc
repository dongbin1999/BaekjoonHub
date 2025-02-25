#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    ll n;scanf("%lld",&n);
    vector<ll> v;
    ll sum=0;
    for(int i=0;i<n;i++){
        ll x,y;scanf("%lld%lld",&x,&y);
        v.push_back(y-x);
        sum+=x;
    }
    vector<ll> p;
    ll d=0;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        p.push_back(v[i]);
        if(p.size()>1)p.back()+=p[i-1];
    }
    int m;scanf("%d",&m);
    while(m--){
        char c;ll x;scanf(" %c %lld",&c,&x);
        if(c=='A')sum+=n*x,d+=x;
        else d-=x;
        auto it=upper_bound(v.begin(),v.end(),d);
        ll num=n-(it-v.begin());
        if(num==n){
            printf("%lld\n",sum+p.back()-d*n);
        }
        else{
            printf("%lld\n",sum+p.back()-p[n-1-num]-num*d);
        }
    }
}