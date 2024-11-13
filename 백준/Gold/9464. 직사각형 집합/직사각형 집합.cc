#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int main(){
    vector<ll> v(1);
    map<pll,ll> ma;
    for(int i=1;i<=1000;i++)for(int j=i+1;j<=1000;j++){
        ll a=2*i*j,b=j*j-i*i,c=j*j+i*i;
        vector<ll> t={a,b,c};
        sort(t.begin(),t.end());
        if(t[1]>500000)continue;
        t[2]=a+a+b+b;
        ll g=gcd(t[0],t[1]);
        t[0]/=g,t[1]/=g;
        pll rec={t[0],t[1]};
        if(ma.count(rec))ma[rec]=min(t[2],ma[rec]);
        else ma[rec]=t[2];
    }
    for(auto [a,b]:ma)v.push_back(b);
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++)v[i]+=v[i-1];

    int n;scanf("%d",&n);
    while(n--){
        int x;scanf("%d",&x);
        printf("%d\n",upper_bound(v.begin(),v.end(),(ll)x)-v.begin()-1);
    }
}