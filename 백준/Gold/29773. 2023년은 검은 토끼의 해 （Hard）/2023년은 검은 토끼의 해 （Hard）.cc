#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[5][2][19],ten[20],goal[5]={3,2,0,2,-1};

int main(){
    ll n;scanf("%lld",&n);
    ll x=0;
    while(n)ten[x++]=n%10,n/=10;
    dp[0][0][0]=1;
    for(int i=0;i<x;i++)
        for(int g=0;g<5;g++)
            for(int d=0;d<=9;d++){
                bool eq=goal[g]==d;
                int b=ten[i]>d?-1:ten[i]!=d;
                for(int o=0;o<2;o++)
                    dp[g+eq][max(0,min(1,b+o))][i+1]+=dp[g][o][i];
            }
    printf("%lld",dp[4][0][x]);
    return 0;
}