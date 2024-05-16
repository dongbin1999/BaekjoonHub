#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());

ll dp[5001][5001];
int x[5001][5001];
int main(){
    int n,q;scanf("%d%d",&n,&q);
    vector<ll> v(n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]);
    vector<ll> vv=v;
    UNIQUE(vv);
    unordered_map<int,int> ma;int num=0;
    for(auto i:vv)ma[i]=num++;
    for(int i=0;i<n;i++){
        if(i)for(int j=0;j<ma.size();j++)x[i][j]=x[i-1][j];
        x[i][ma[v[i]]]++;
    }

    for(int len=3;len<=n;len++)for(int l=0,r=l+len-1;r<n;l++,r++){
        ll val=v[l]+v[r];
        ll y=ma.count(-val)?x[r-1][ma[-val]]:0,
        z=ma.count(-val)?x[l][ma[-val]]:0;
        dp[l][r]=y-z+dp[l+1][r]+dp[l][r-1]-dp[l+1][r-1];
    }
    while(q--){
        int l,r;scanf("%d%d",&l,&r);
        printf("%lld\n",dp[l-1][r-1]);
    }
}