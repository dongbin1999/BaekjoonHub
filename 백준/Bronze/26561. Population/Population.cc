#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;scanf("%d",&t);
    while(t--){
        ll a,b;scanf("%lld%lld",&a,&b);
        printf("%lld\n",a+b/4-b/7);
    }
    return 0;
}