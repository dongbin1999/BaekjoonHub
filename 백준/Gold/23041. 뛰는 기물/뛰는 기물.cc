#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
int main(){
    ll a,b;scanf("%lld%lld",&a,&b);
    ll gcd=GCD(a,b);
    printf("%lld",gcd*gcd*(a/gcd&b/gcd&1?2:1));
}