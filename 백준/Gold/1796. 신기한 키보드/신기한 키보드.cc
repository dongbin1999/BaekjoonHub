#include<bits/stdc++.h>
using namespace std;
char s[52];

int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    map<char,pair<int,int>> ma;
    for(int i=1;i<=n;i++)
        if(!ma.count(s[i]))ma[s[i]]={i,i};
        else ma[s[i]]={min(ma[s[i]].first,i),max(ma[s[i]].second,i)};
    vector<int> dp(n+1);
    for(int i=1;i<=n;i++)dp[i]=i-1;
    for(auto [c,lr]:ma){
        vector<int> tmp(n+1,1e9);
        auto [l,r]=lr;int len=r-l;
        for(int i=-n;i<=n;i++){
            int nr=r+i;
            if(nr>=1&&nr<=n)tmp[nr]=min(tmp[nr],dp[l]+len+abs(i));
        }
        for(int i=-n;i<=n;i++){
            int nl=l+i;
            if(nl>=1&&nl<=n)tmp[nl]=min(tmp[nl],dp[r]+len+abs(i));
        }
        dp=tmp;
    }
    printf("%d",*min_element(dp.begin(),dp.end())+n);
}