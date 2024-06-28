#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b;scanf("%lld%lld",&a,&b);
    if(a/gcd(a,b)+b/gcd(a,b)&1)printf("0");
    else printf("%lld",gcd(a,b));
    return 0;
}