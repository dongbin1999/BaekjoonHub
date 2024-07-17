#include<bits/stdc++.h>
using namespace std;

double a[20][20];

void solve(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%lf",&a[i][j]);
    double ans=-2e18;
    for(int d=1;d<1<<n;d++){
        double tmp=0;
        for(int i=0;i<n;i++)for(int j=i;j<n;j++)
            if((d>>i&1)&&(d>>j&1))tmp+=a[i][j];
        ans=max(ans,tmp);
    }
    printf("%.2lf\n",round(ans*100)/100.0);
}
int main(){
    int tc;scanf("%d",&tc);
    for(int i=1;i<=tc;i++){
        printf("Data Set %d:\n",i);
        solve();
    }
}