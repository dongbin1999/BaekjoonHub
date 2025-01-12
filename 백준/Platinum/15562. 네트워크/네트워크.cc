#include<bits/stdc++.h>
using namespace std;
int a[1000001];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        a[y]++,a[x]--;
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans+=max(0,a[i]);
    printf("%d",ans);
}