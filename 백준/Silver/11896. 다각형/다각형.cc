#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a,b;scanf("%lld%lld",&a,&b);
    b/=2,a=(a-1)/2;
    b=max(b*(b+1)-2,0ll),a=max(a*(a+1)-2,0ll);
    printf("%lld",b-a);
}