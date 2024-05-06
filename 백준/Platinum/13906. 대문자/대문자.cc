#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod=1e9+7;

char s[1002];
vector<int> b[26];

int idx(int cur,int al){
    int l=upper_bound(b[al].begin(),b[al].end(),cur)-b[al].begin();
    if(l+2>=b[al].size())return -1;
    return b[al][l+2];
}
ll solve(){
    for(int i=0;i<26;i++)b[i].clear();
    int n=strlen(s+1);
    for(int i=1;i<=n;i++)b[s[i]-'a'].push_back(i);
    vector<ll> dp(n+1,0),init(n+1);
    dp[0]=1;
    ll ans=0;
    for(int len=0;len<=n;len++){
        vector<ll> tmp=init;
        for(int nx_al=0;nx_al<26;nx_al++)for(int cur=0;cur<=n;cur++){
                if(!dp[cur])continue;
                int nx_pos=idx(cur,nx_al);
                if(nx_pos==-1)continue;
                tmp[nx_pos]=(tmp[nx_pos]+dp[cur])%mod;
            }
        dp=tmp;
        for(int cur=0;cur<=n;cur++)ans=(ans+dp[cur])%mod;
    }
    return ans;
}

int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    ll x=solve();
    for(int l=1,r=n;l<=r;l++,r--)swap(s[l],s[r]);
    ll y=solve();
    assert(x==y);
    printf("%lld",x);
    return 0;
}