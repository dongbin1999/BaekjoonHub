#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll base=31,mod=1234567891;
char s[100];
int main(){
    int n;scanf("%d %s",&n,s+1);
    ll ans=0;
    for(int i=n;i>=1;i--){
        ans=(ans*base+s[i]-'a'+1)%mod;
    }
    printf("%lld",ans);
    return 0;
}