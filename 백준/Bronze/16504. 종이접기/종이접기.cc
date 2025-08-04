#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    n=n*n;
    ll x=0;
    while(n--){
        ll y;scanf("%lld",&y);
        x+=y;
    }
    printf("%lld",x);
}