#include<bits/stdc++.h>
using namespace std;

int dp[1001];
int go(int n){
    if(n<2)return 0;
    if(dp[n]!=-1)return dp[n];
    priority_queue<int,vector<int>,greater<int>> pq;
    int mex=0;
    for(int i=2;i<=n;i++)pq.push(go(i-2)^go(n-i));
    while(!pq.empty()){
        if(mex<pq.top())break;
        if(mex==pq.top())mex++;
        pq.pop();
    }
    return dp[n]=mex;
}

int main(){
    int n;scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    printf("%d",!go(n)+1);
    return 0;
}