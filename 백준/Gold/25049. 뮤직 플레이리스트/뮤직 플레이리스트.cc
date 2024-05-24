#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[500002],l[500002],r[500001],sum;

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&p[i]),sum=max(0ll,sum+p[i]),l[i]=max(l[i-1],sum);
    sum=0;
    for(int i=n;i>=1;i--)sum=max(0ll,sum+p[i]),r[i]=max(r[i+1],sum);
    sum=0;
    for(int i=1;i<=n;i++)sum+=p[i];
    ll ans=sum;
    for(int i=0;i<=n;i++)ans=max(ans,sum+l[i]+r[i+1]);
    printf("%lld",ans);
}