#include<cstdio>
bool v[1<<20];
int main(){
    int n,m,x;scanf("%d%d",&n,&m);
    while(m--)scanf("%d",&x),v[x]=1;
    long long ans=0;
    for(int i=3;i<=n;i++)ans+=v[i]?0:i-(1<<(31-__builtin_clz(i)));
    printf("%lld",ans<<1);
}