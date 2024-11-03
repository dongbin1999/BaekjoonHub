#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=9999991;
ll power(ll a,ll b){ll ret=1;while(b){if(b%2)ret=ret*a%mod;a=a*a%mod;b/=2;}return ret;}
ll fac[21]={1,1};
ll cmb(ll a,ll b){return fac[a]*power(fac[b],mod-2)%mod*power(fac[a-b],mod-2)%mod;}

void solve(){
    int n;scanf("%d",&n);
    vector<vector<int>> v(1);
    ll ans=1;
    for(int i=1;i<=n;i++)v[0].push_back(i);
    while(n--){
        int x;scanf("%d",&x);
        for(int i=0;i<v.size();i++){
            int p=-1;
            for(int j=0;j<v[i].size();j++)if(v[i][j]==x){p=j;break;}
            if(p==-1)continue;
            ans=ans*cmb((ll)v[i].size()-1,p)%mod;
            vector<int> a,b;
            for(int j=0,c=0;j<v[i].size();j++){
                (c?b:a).push_back(v[i][j]);
                if(v[i][j]==x)c=1,a.pop_back();
            }
            v.push_back(a),v.push_back(b);
            v.erase(v.begin()+i);
            break;
        }
    }
    printf("%lld\n",ans);
}

int main(){
    for(int i=1;i<=20;i++)fac[i]=fac[i-1]*i%mod;
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}