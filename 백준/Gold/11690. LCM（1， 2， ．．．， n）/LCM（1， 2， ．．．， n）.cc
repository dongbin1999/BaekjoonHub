#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool a[100000001];

int main(){
    int n;scanf("%d",&n);
    for(int i=2;i*i<=n;i++){
        if(a[i])continue;
        for(int j=i*i;j<=n;j+=i)
            a[j]=1;
    }
    ll ans=1,mod=(1ll<<32)-1;
    for(int i=2;i<=n;i++){
        if(a[i])continue;
        ll nn=n;
        while(nn/i)ans=(ans*i)&mod,nn/=i;
    }
    printf("%lld",ans);
    return 0;
}