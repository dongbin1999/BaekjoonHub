#include<bits/stdc++.h>
using namespace std;
bool dp[3][10001];
char x[10003],y[10003];

int main(){
    int n;scanf("%d",&n);
    scanf("%s %s",x+1,y+1);
    string a=" ";a+=x+1;
    string b=" ";b+=y+1;
    int l,r;scanf("%d%d",&l,&r);l++,r++;
    string s={0,a[l],a[r]};
    a.erase(r,1),a.erase(l,1);
    dp[0][0]=1;
    for(int i=0;i<=2;i++)for(int j=0;j+i<n;j++){
        if(a[j+1]==b[j+i+1])dp[i][j+1]|=dp[i][j];
        if(i<2&&s[i+1]==b[j+i+1])dp[i+1][j]|=dp[i][j];
    }
    printf(dp[2][n-2]?"YES":"NO");
}