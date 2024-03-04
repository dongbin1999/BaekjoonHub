#include <bits/stdc++.h>
using namespace std;

bool b[250][250][51];

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        b[i][i][x]=1;
    }
    for(int len=2;len<=n;len++)
        for(int l=1,r=l+len-1;r<=n;l++,r++)
            for(int v=l;v<r;v++)for(int x=1;x<50;x++)
                if(b[l][v][x]&&b[v+1][r][x])b[l][r][x+1]=1;
    int ans=0;
    for(int l=1;l<=n;l++)for(int r=l;r<=n;r++)for(int x=1;x<50;x++)
        if(b[l][r][x])ans=max(ans,x);
    printf("%d",ans);
}
