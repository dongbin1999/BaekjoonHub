#include<bits/stdc++.h>
using namespace std;
int mx[14][1000001],mn[14][1000001];

int main(){
    int n,m,c;scanf("%d%d%d",&n,&m,&c);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        mx[0][i]=mn[0][i]=x;
        for(int j=1;j<14;j++){
            mx[j][i]=max(mx[j-1][i],mx[j-1][max(0,i-(1<<(j-1)))]);
            mn[j][i]=min(mn[j-1][i],mn[j-1][max(0,i-(1<<(j-1)))]);
        }
    }
    int d=0;while((1<<d)<=m)d++;d--;

    bool none=1;
    for(int i=m;i<=n;i++){
        int a=max(mx[d][i],mx[d][i-(m-(1<<d))]),
        b=min(mn[d][i],mn[d][i-(m-(1<<d))]);
        if(a-b<=c)none=0,printf("%d\n",i-m+1);
    }
    if(none)printf("NONE");
}