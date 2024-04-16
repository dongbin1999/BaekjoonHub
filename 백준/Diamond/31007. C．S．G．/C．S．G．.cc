#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
bool isprime(int x){
    for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
    return 1;
}
int cache[1<<22],joker;
vector<int> v;
bool win(int bit=0){
    if(cache[bit]!=-1)return cache[bit];
    bool ret=0;
    for(int i=0;i<v.size();i++){
        if(bit&v[i])continue;
        ret|=!win(bit|v[i]);
    }
    return cache[bit]=ret;
}

void solve(){
    memset(cache,-1,sizeof(cache)),v.clear(),joker=0;
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
    if(joker&1)v.push_back(1<<21);
    bool ans=win();
    printf(ans?"amsminn\n":"bnb2011\n");
}

int main(){
    for(int i=2;i<=75;i++)if(isprime(i))prime.push_back(i);
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}