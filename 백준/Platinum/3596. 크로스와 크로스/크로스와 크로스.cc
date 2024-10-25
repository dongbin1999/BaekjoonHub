#include <bits/stdc++.h>
using namespace std;
int dp[2001];
int main() {
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        vector<int> v(i+1,0);
        int mex=0;
        for(int x=1;x<=i;x++){
            int l=max(0,x-3),r=max(0,i-x-2);
            v[dp[l]^dp[r]]++;
            while(v[mex])mex++;
        }
        dp[i]=mex;
    }
    printf("%d",!dp[n]+1);
    return 0;
}