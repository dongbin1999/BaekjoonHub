#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll,4> arr;
const ll mod=1e9+7;
arr a,p[10];
arr operator+(arr A,arr B){
    arr C=A;
    for(int i=0;i<C.size();i++)C[i]=min(a[i],C[i]+B[i]);
    return C;
}

ll zero;
ll ans(string s,bool X){
    vector<map<arr,ll>> dp(2);
    dp[0][{0,0,0,0}]=1;
    ll ret=0;zero=0;
    string ss=s;reverse(ss.begin(),ss.end());
    for(auto i:ss)zero=(zero*10+i-'0')%mod;

    for(int _=0;_<s.size();_++){
        int n=s[_]-'0';vector<map<arr,ll>> nx(2);
        for(int i=1;i<n;i++){
            for(auto [A,cnt]:dp[0])nx[0][A+p[i]]=(nx[0][A+p[i]]+cnt)%mod;
            for(auto [A,cnt]:dp[1])nx[0][A+p[i]]=(nx[0][A+p[i]]+cnt)%mod;
        }
        for(int i=n+1;i<=9;i++){
            for(auto [A,cnt]:dp[0])nx[1][A+p[i]]=(nx[1][A+p[i]]+cnt)%mod;
            for(auto [A,cnt]:dp[1])nx[1][A+p[i]]=(nx[1][A+p[i]]+cnt)%mod;
        }
        if(n){
            for(auto [A,cnt]:dp[0])nx[0][A+p[n]]=(nx[0][A+p[n]]+cnt)%mod;
            for(auto [A,cnt]:dp[1])nx[1][A+p[n]]=(nx[1][A+p[n]]+cnt)%mod;
        }
        dp=nx;
        for(int x=0;x<2;x++)
            for(auto [A,cnt]:dp[x]){
                bool b=1;
                for(int i=0;i<A.size();i++)b&=A[i]>=a[i];
                if(b)ret=(ret+cnt)%mod;
                zero=(zero+mod-cnt)%mod;
            }
    }
    for(auto [A,cnt]:dp[1]){
        bool b=1;
        for(int i=0;i<A.size();i++)b&=A[i]>=a[i];
        if(b)ret=(ret-cnt+mod)%mod;
        zero=(zero+cnt)%mod;
    }
    return X?ret:0;
}

int main(){
    ll k;string l,r;cin>>k>>l>>r;

    while(k%2==0)k/=2,a[0]++;while(k%3==0)k/=3,a[1]++;
    while(k%5==0)k/=5,a[2]++;while(k%7==0)k/=7,a[3]++;
    p[0]=a,p[1]={0,0,0,0},p[2]={1,0,0,0},p[3]={0,1,0,0},p[4]={2,0,0,0},
    p[5]={0,0,1,0},p[6]={1,1,0,0},p[7]={0,0,0,1},p[8]={3,0,0,0},p[9]={0,2,0,0};

    reverse(r.begin(),r.end()),reverse(l.begin(),l.end());
    ll R=(ans(r,k==1)+zero)%mod,L=(ans(l,k==1)+zero)%mod;
    //l이 k - special이면 ans+1출력해야함.
    arr la={0,0,0,0};
    bool z=0;
    for(auto i:l)la=la+p[i-'0'],z|=i=='0';
    if(la==a&&k==1||z)L--;
    cout<<(R-L+mod)%mod;
    return 0;
}