#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1001][1001];
int main(){
    int n,m;scanf("%d%d",&n,&m);
    ll mn=1e18,sum=0,x=n*m;
    while(x--){
        ll k;scanf("%lld",&k);
        mn=min(mn,k),sum+=k;
    }
    printf("%lld",sum-mn);
}