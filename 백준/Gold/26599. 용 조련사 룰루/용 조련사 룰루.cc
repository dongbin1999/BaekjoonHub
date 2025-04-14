#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int main(){
    int n;ll m;scanf("%d%lld",&n,&m);
    vector<pll> v(n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i].first),v[i].second=i+1;
    sort(v.begin(),v.end());
    for(int i=n-1;i>=max(1,n-3);i--)if(v[i].first>v[i-1].first+m)return !printf("NO");
    printf("YES\n");
    for(int i=n-3;i>=0;i--)printf("%lld ",v[i].second);
    for(int i=max(0,n-2);i<n;i++)printf("%lld ",v[i].second);
}