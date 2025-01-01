#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;scanf("%d",&n);
    int x=sqrt(n),ans=1e9;
    for(int i=max(0,x-2);i<=x+2;i++)for(int j=max(0,x-2);j<=x+2;j++)
        if(i*j>=n)ans=min(ans,(i+j)*2);
    printf("%d\n",ans);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}