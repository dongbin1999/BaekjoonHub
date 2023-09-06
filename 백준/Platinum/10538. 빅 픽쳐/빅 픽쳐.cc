#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ps=2;
const ll mod[ps]={998244353,1000000007},base=2;
ll power[4000001][ps];
char a[2020][2020],b[2020][2020];
ll an[2020][2020][ps],bn[2020][2020][ps];
int main(){
    for(int p=0;p<ps;p++)for(int i=0;i<=4000000;i++)
            power[i][p]=i?power[i-1][p]*base%mod[p]:1;
    int r,c,n,m;scanf("%d%d%d%d",&r,&c,&n,&m);
    for(int i=0;i<r;i++){
        scanf("%s",a[i]);
        for(int p=0;p<ps;p++)for(int j=0;j<c;j++)
                an[i][j][p]=((j?an[i][j-1][p]:0)+(a[i][j]=='o'?power[j][p]:0))%mod[p];
    }
    for(int i=0;i<n;i++){
        scanf("%s",b[i]);
        for(int p=0;p<ps;p++)for(int j=0;j<m;j++)
                bn[i][j][p]=((j?bn[i][j-1][p]:0)+(b[i][j]=='o'?power[j][p]:0))%mod[p];
    }
    int ans=0;
    for(int le=0,ri=le+c-1;ri<m;le++,ri++){
        vector<ll> x(ps),y(ps);
        for(int p=0;p<ps;p++){
            for(int j=0;j<r;j++){
                x[p]=(x[p]+an[j][c-1][p]*power[j*c+le][p])%mod[p];
                y[p]=(y[p]+(bn[j][ri][p]-(le?bn[j][le-1][p]:0)+mod[p])%mod[p]*power[j*c][p])%mod[p];
            }
        }
        ans+=x==y;
        for(int i=r;i<n;i++){
            for(int p=0;p<ps;p++){
                x[p]=x[p]*power[c][p]%mod[p];
                y[p]-=(bn[i-r][ri][p]-(le?bn[i-r][le-1][p]:0)+mod[p])%mod[p]*power[(i-r)*c][p]%mod[p];
                y[p]+=mod[p];
                y[p]+=(bn[i][ri][p]-(le?bn[i][le-1][p]:0)+mod[p])%mod[p]*power[i*c][p]%mod[p];
                y[p]%=mod[p];
            }
            ans+=x==y;
        }
    }
    printf("%d",ans);
}