#include<bits/stdc++.h>
using namespace std;
#define upd(x,y) x=max(x,y)
int dp[1000][1000],b[1000];
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&b[i]);
    for(int len=0;len<=n;len++)for(int l=0,r=l+len-1;r<n;l++,r++){
            for(int m=l;m<r;m++)upd(dp[l][r],dp[l][m]+dp[m+1][r]);
            if(l-1>=0&&r+1<n&&b[l-1]==b[r+1])upd(dp[l-1][r+1],dp[l][r]+1);
        }
    printf("%d",dp[0][n-1]);
}