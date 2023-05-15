#include <bits/stdc++.h>
using namespace std;
#define f(x) (1<<(31-__builtin_clz(x)))
typedef long long ll;
int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<bool> v(1000001,0);
    while(m--){
        int x;scanf("%d",&x);
        v[x]=1;
    }
    ll ans=0;
    for(int i=3;i<=n;i++){
        if(v[i])continue;
        int x=i-f(i);
        while(x)ans+=f(x),x-=f(x);
    }
    printf("%lld",ans<<1);
    return 0;
}