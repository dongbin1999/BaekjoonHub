#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a={0,2,2};

void go(ll n,ll k){
    if(k==1){printf("(\n");return;}
    if(k==a[n]){printf(")\n");return;}
    ll l=a[n-2];
    if(1+l>=k)go(n-2,k-1);
    else go(n-1,k-1-l);
}

void solve(){
    ll n,k;scanf("%lld%lld",&n,&k);
    ll d=max(0ll,n-(ll)a.size()+2)/2;
    n-=d*2,k-=d;
    if(k<1){printf("(\n");return;}
    if(a[n]<k){printf("0\n");return;}
    go(n,k);
}

int main(){
    while(a.back()<=4e18)a.push_back(a[a.size()-2]+a.back()+2);
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}