#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int GCD(int a,int b){return b?GCD(b,a%b):a;}

vector<vector<int>> fac(1000001);
void solve(){
    int n;scanf("%d",&n);
    vector<int> v(n),a(1000001);
    for(int i=0;i<n;i++)scanf("%d",&v[i]),a[v[i]]++;
    ll ans=0;
    for(auto x:v)for(auto f:fac[x])ans+=a[x-f];
    printf("%lld\n",ans);
}
int main(){
    for(int i=1;i<=1e6;i++)
        for(int f=1;f*f<=i;f++){
            if(i%f)continue;
            if((i|f)==i)fac[i].push_back(f);
            if(i/f!=f&&(i|(i/f))==i)fac[i].push_back(i/f);
        }
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}