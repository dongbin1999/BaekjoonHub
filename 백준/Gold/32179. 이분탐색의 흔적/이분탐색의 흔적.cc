#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll a[101],c[101][101];
int main(){
    int n,k;scanf("%d%d",&n,&k);
    vector<ll> v(k);
    for(int i=0;i<k;i++)scanf("%lld",&v[i]);
    memset(a,-1,sizeof(a));
    ll l=1,r=n,mid;
    for(int i=0;i<k-1;i++){
        mid=(l+r)/2,a[mid]=v[i];
        if(v[i]>v[i+1])r=mid-1;
        else l=mid+1;
    }
    for(int i=0;i<=100;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
    mid=(l+r)/2,a[mid]=v[k-1],a[n+1]=101;
    ll len=0,pre=0,ans=1;
    for(int i=1;i<=n+1;i++){
        if(a[i]<0){len++;continue;}
        //printf("%d %lld %lld %lld: %lld\n",i,pre,a[i],len,c[a[i]-pre-1][len]);
        ans=(ans*c[a[i]-pre-1][len])%mod,pre=a[i],len=0;
    }
    printf("%lld",ans);
}