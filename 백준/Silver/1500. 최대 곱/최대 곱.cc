#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll s,k;scanf("%lld%lld",&s,&k);
    ll ans=1,x=s/k,y=s%k;
    for(int i=0;i<k;i++)ans*=x+(y>i);
    printf("%lld",ans);
}