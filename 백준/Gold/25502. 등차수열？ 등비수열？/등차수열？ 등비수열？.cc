#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll a[300000];

int main() {
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    map<pll,int> x;map<ll,int> y;
    for(int i=1;i<n;i++){
        ll p=a[i-1],q=a[i],g=gcd(p,q);
        y[q-p]++,x[{q/g,p/g}]++;
    }
    while(m--){
        int i;ll j;scanf("%d%lld",&i,&j);i--;
        if(i){
            ll p=a[i-1],q=a[i],g=gcd(p,q);
            if(--y[q-p]==0)y.erase(y.find(q-p));
            if(--x[{q/g,p/g}]==0)x.erase(x.find({q/g,p/g}));
            q=j,g=gcd(p,q),y[q-p]++,x[{q/g,p/g}]++;
        }
        if(i+1<n){
            ll p=a[i],q=a[i+1],g=gcd(p,q);
            if(--y[q-p]==0)y.erase(y.find(q-p));
            if(--x[{q/g,p/g}]==0)x.erase(x.find({q/g,p/g}));
            p=j,g=gcd(p,q),y[q-p]++,x[{q/g,p/g}]++;
        }
        a[i]=j;
        if(y.size()==1&&y.begin()->first>0)printf("+\n");
        else if(x.size()==1){
            ll X=x.begin()->first.first,Y=x.begin()->first.second;
            if(X>=Y&&X%Y==0)printf("*\n");
            else printf("?\n");
        }
        else printf("?\n");
    }
}