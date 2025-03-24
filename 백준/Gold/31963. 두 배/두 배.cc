#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    ll pm=0,px=1,ans=0;
    for(int i=0;i<n;i++){
        ll x;scanf("%lld",&x);
        ll cm=0;
        for(ll j=max(0ll,pm-25);;j++){
           ll z=j<pm?x>>(pm-j):x<<(j-pm);
           if(z>=px){cm=j;break;}
        }
        ans+=cm,pm=cm,px=x;
    }
    printf("%lld",ans);
}