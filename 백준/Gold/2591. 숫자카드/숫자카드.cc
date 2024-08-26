#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[50];
char s[43];
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    dp[0]=1;
    for(int i=0;i<n;i++){
        if(s[i+1]=='0')continue;
        dp[i+1]+=dp[i];
        if(i+2<=n){
            string x;
            x+=s[i+1],x+=s[i+2];
            int y=stoi(x);
            if(y<=34)dp[i+2]+=dp[i];
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}