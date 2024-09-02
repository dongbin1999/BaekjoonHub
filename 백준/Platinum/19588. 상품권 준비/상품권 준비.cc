#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<pll> v(n);
    for(auto &[x,y]:v)scanf("%lld%lld",&x,&y);
    sort(v.begin(),v.end());
    vector<ll> xorsum(1);
    for(int i=0;i<n;i++)xorsum.push_back(xorsum.back()^v[i].second);
    vector<vector<ll>> sum(m,vector<ll>(n/m+2));
    for(int i=m;i<=n;i++)sum[i%m][i/m]=sum[i%m][i/m-1]+(xorsum[i]^xorsum[i-m]);
    int q;scanf("%d",&q);
    while(q--){
        int a,b;scanf("%d%d",&a,&b);
        int x=n-b-a*m,l=x/m+1,r=l+a-1;
        printf("%lld\n",sum[x%m][r]-sum[x%m][l-1]);
    }
}