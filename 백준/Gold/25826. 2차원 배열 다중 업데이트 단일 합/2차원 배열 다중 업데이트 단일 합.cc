#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1002][1002],sum[1002][1002],b;

void init(int n){
    if(b)return; b=1;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
        sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
    }
}

void add(int i1,int j1,int i2,int j2,int k){
    a[i1][j1]+=k,a[i2+1][j1]-=k,a[i1][j2+1]-=k,a[i2+1][j2+1]+=k;
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        int k;scanf("%d",&k);
        add(i,j,i,j,k);
    }

    while(m--){
        int q;scanf("%d",&q);
        if(q==1){
            int i1,i2,j1,j2,k;scanf("%d%d%d%d%d",&i1,&j1,&i2,&j2,&k);
            i1++,i2++,j1++,j2++;
            add(i1,j1,i2,j2,k);
        }
        else{
            init(n);
            int i1,i2,j1,j2;scanf("%d%d%d%d",&i1,&j1,&i2,&j2);
            i1++,i2++,j1++,j2++;
            printf("%lld\n",sum[i2][j2]-sum[i1-1][j2]-sum[i2][j1-1]+sum[i1-1][j1-1]);
        }
    }
    return 0;
}