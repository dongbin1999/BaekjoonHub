#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum[500001][2];
void solve(){
    int n,a,b;scanf("%d%d%d",&n,&a,&b);
    if(a<b)swap(a,b);
    printf("%lld\n",sum[n][1]*a+sum[n][0]*b);
}

int main(){
    for(int i=1;i<=500000;i++){
        int x=1<<(31-__builtin_clz(i+1));x--;
        ll a=__builtin_popcount(x),b=__builtin_popcount(i-x);
        sum[i][0]=sum[i-1][0]+b,sum[i][1]=sum[i-1][1]+a;
    }
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}