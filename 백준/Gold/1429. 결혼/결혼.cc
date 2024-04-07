#include<bits/stdc++.h>
using namespace std;
char s[13];
int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<bitset<12>> v(n),vv(m);
    bitset<12> b;
    for(int i=0;i<n;i++){
        scanf("%s",s);
        for(int j=0;j<m;j++)v[i][j]=vv[j][i]=s[j]=='1';
        b|=v[i];
        if(v[i].none())return !printf("-1");
    }
    if(b.count()<m)return !printf("-1");
    int ans=1e9;

    for(int i=0;i<1<<n;i++)for(int j=0;j<1<<m;j++){
        bitset<12> M,W;
        for(int x=0;x<n;x++)if(i>>x&1)W|=v[x],M[x]=1;
        for(int y=0;y<m;y++)if(j>>y&1)M|=vv[y],W[y]=1;
        if(M.count()==n&&W.count()==m)
            ans=min(ans,__builtin_popcount(i)+__builtin_popcount(j));
    }
    printf("%d",ans);
    return 0;
}