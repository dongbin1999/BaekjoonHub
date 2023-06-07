#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    vector<ll> v(n);
    ll sum=0;
    for(int i=0;i<n;i++)scanf("%lld",&v[i]),sum+=v[i];
    ll mx=*max_element(v.begin(),v.end());
    printf("%lld",sum-mx+1<mx?(sum-mx)*2+1:sum);
    return 0;
}
