#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[11];
int main(){
    vector<ll> v(1024);
    int n,k;scanf("%d%d",&n,&k);
    while(n--){
        int x=0;
        scanf("%s",s);
        for(int i=0;i<10;i++)x|=1<<(s[i]-'0');
        v[x]++;
    }
    ll ans=0;
    for(int i=0;i<1024;i++)for(int j=i+1;j<1024;j++)
        if(__builtin_popcount(i|j)==k)ans+=v[i]*v[j];
    for(int i=0;i<1024;i++)
        if(__builtin_popcount(i)==k)ans+=v[i]*(v[i]-1)/2;
    printf("%lld",ans);
}