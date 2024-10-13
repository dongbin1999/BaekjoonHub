#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,a;ll b;scanf("%d%lld%d",&n,&b,&a);
    vector<ll> v(n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]);
    sort(v.begin(),v.end());
    int l=0,r=n,mid,ans=0;
    while(l<=r){
        mid=l+r>>1;
        ll sum=0;
        for(int i=0;i<mid;i++)sum+=v[i];
        for(int i=mid-1;i>=max(0,mid-a);i--)sum-=v[i]/2;
        if(sum<=b)ans=max(ans,mid),l=mid+1;
        else r=mid-1;
    }
    printf("%d",ans);
}