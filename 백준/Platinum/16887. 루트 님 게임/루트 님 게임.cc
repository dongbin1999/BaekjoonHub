#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1000000,mx=7;

int dp[sz+1],b[mx][sz+1];
int go(ll x){
    if(dp[x]!=-1)return dp[x];
    ll r=sqrt(x),l=sqrt(r);
    while(r*r>x||r>=x)r--;
    while(l*l*l*l<x)l++;
    vector<int> v(mx+1);
    int mex=0;
    for(ll i=l;i<=r;i++){
        v[go(i)]++;
        while(v[mex])mex++;
    }
    return dp[x]=mex;
}

int main(){
    int n;scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    for(ll x=1;x<=sz;x++){
        int mex=0;
        if(x<=10000)mex=go(x);
        else{
            ll r=sqrt(x),l=sqrt(r);
            while(r*r>x||r>=x)r--;
            while(l*l*l*l<x)l++;
            for(int j=0;j<mx;j++)
                if(b[j][r]-b[j][l-1])mex++;
                else break;
            dp[x]=mex;
        }
        for(int i=0;i<mx;i++)
            b[i][x]=b[i][x-1]+(mex==i);
    }
    int XOR=0;
    while(n--){
        ll x,mex=0;scanf("%lld",&x);
        if(x<=sz)mex=dp[x];
        else{
            ll r=sqrt(x),l=sqrt(r);
            while(r*r>x||r>=x)r--;
            while(l*l*l*l<x)l++;
            for(int i=0;i<mx;i++)
                if(b[i][r]-b[i][l-1])mex++;
                else break;
        }
        XOR^=mex;
    }
    printf(XOR?"koosaga":"cubelover");
    return 0;
}