#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;scanf("%d",&n);
    vector<ll> v(n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]);
    sort(v.begin(),v.end(),greater<ll>());
    ll ans=0;
    vector<ll> vv;
    for(int i=1;i<n;i++){
        if(v[i-1]-v[i]>1)continue;
        else vv.push_back(v[i]),i++;
    }
    for(int i=1;i<vv.size();i+=2)ans+=vv[i]*vv[i-1];
    printf("%lld",ans);
    return 0;
}