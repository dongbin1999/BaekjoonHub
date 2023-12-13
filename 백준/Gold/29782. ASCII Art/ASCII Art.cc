#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n;scanf("%lld",&n);
    ll l=0,r=1e8,mid,a=0;
    while(l<=r){
        mid=l+r>>1;
        if(mid*(mid+1)*26/2<n)a=max(a,mid),l=mid+1;
        else r=mid-1;
    }
    for(ll i=0,j=a*(a+1)/2*26+a+1;i<26;i++,j+=a+1){
        if(j>=n){
            printf("%c\n",'A'+i);
            return;
        }
    }
}
int main(){
    int t;scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}