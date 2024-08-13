#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;scanf("%d",&n);
    vector<ll> v(n+1,0);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]);
    for(int i=n-1;i>=0;i--)v[i]=min(v[i],v[i+1]+1);
    printf("%lld",accumulate(v.begin(),v.end(),0ll));
    return 0;
}