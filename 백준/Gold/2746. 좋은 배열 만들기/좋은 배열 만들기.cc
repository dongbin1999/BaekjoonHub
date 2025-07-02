#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    vector<ll> v(n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]);
    sort(v.begin(),v.end());
    ll ans=0,sum=0;

    for(auto i:v)sum+=i;
    for(int i=0;i+1<n;i++){
        ll s=sum-v[i];
        ll l=lower_bound(v.begin()+i+1,v.end(),s-v.back()*2)-v.begin();
        ll r=upper_bound(v.begin()+i+1,v.end(),s-v.back()*2)-v.begin();
        ans+=r-l;
    }
    sum-=v.back(),n--,v.pop_back();
    for(int i=0;i+1<n;i++){
        ll s=sum-v[i];
        if(v.back()*2==s)ans++;
    }
    sum-=v.back(),n--,v.pop_back();
    if(v.back()*2==sum)ans++;
    printf("%lld",ans);
}