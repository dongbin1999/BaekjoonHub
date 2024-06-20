#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c(ll a,ll b){
    ll ret=1;
    for(ll i=1;i<=b;i++)
        ret*=a+1-i,ret/=i;
    return ret;
}
void solve(){
    ll a,b;scanf("%lld%lld",&a,&b);
    printf("%lld\n",c(a+b-2,min(a-1,b-1)));
}

int main(){
    int tc;scanf("%d",&tc);
    for(int i=1;i<=tc;i++){
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}