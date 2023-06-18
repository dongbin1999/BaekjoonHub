#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;scanf("%d",&n);
    vector<ll> v(n);
    ll ans=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&v[i]);
        if(i)ans+=abs(v[i-1]),v[i]+=v[i-1];
    }
    printf("%lld",ans);
    return 0;
}