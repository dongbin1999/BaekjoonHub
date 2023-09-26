#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
ll cmb[1001][1001]={1};
int main(){
    int k;scanf("%d",&k);
    for(int i=1;i<=1000;i++)for(int j=0;j<=i;j++)
        cmb[i][j]=j?(cmb[i-1][j-1]+cmb[i-1][j])%mod:1;
    vector<ll> c(k+1);
    ll sum=0,ans=1;
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);c[i]--;
        ans=(ans*cmb[i+sum+c[i]-1][c[i]])%mod;
        sum+=c[i];
    }
    printf("%lld",ans);
    return 0;
}