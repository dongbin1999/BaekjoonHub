#include<bits/stdc++.h>
using namespace std;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
vector<int> prime;
bool isprime(int x){
    for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
    return 1;
}
int dp[1<<22],joker;
vector<int> v;
bool win(int bit){
    if(dp[bit]!=-1)return dp[bit];
    bool ret=0;
    for(int i=0;i<v.size();i++){
        if(bit&v[i])continue;
        ret|=!win(bit|v[i]);
    }
    return dp[bit]=ret;
}

void solve(){
    memset(dp,-1,sizeof(dp)),v.clear(),joker=0;
    int n,m;scanf("%d%d",&n,&m);
    set<int> se;
    while(m--){
        int x;scanf("%d",&x);
        if(x>1)se.insert(x);
        else joker++;
    }
    for(auto val:se){
        int bit=0,x=val;
        for(int i=0;i<prime.size();i++)
            if(x%prime[i]==0){
                bit|=1<<i;
                while(x%prime[i]==0)x/=prime[i];
            }
        if(x>75)joker++;
        else v.push_back(bit);
    }
    UNIQUE(v)
    if(joker&1)v.push_back(1<<21);
    printf(win(0)?"amsminn\n":"bnb2011\n");
}

int main(){
    for(int i=2;i<=75;i++)if(isprime(i))prime.push_back(i);
    int t;scanf("%d",&t);
    while(t--)solve();
}