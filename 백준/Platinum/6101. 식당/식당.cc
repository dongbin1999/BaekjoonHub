//참고 : https://cyberflower.github.io/2019/07/22/icpc6101.html
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;scanf("%d%d",&n,&m);
    int root=sqrt(n);
    //그룹의 크기를 x까지 늘리면, group[x]부터 i까지 커버 가능.
    vector<int> dp(n+1,1e9),group(root+2,1),cow(m+1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int p;scanf("%d",&p);
        for(int sz=root;sz>=2;sz--)
            /*소 i-1가 만든 크기 sz인 그룹[prev_group[sz]~i-1]안에, 음식 p가 있었다면?
             *소 i가 만들 크기 sz인 그룹[group[sz]~i]이 커버하는 범위는 그대로 유지.
             *음식 p가 없었다면?
             *크기 sz-1인 그룹[prev_group[sz-1]~i-1]이 커버하는 구간에,
             *해당 그룹에 없던 p가 추가되면서 크기가 +1됨 -> [prev_group[sz-1]~i]*/
            if(cow[p]<group[sz])group[sz]=group[sz-1];

        //직전 소와 같은 음식을 먹은게 아니면..
        if(cow[p]!=i-1)group[1]=i;

        //음식 p를 가장 최근에 먹은 소는 i이다.
        cow[p]=i;

        for(int sz=1;sz<=root;sz++)
            dp[i]=min(dp[i],dp[group[sz]-1]+sz*sz);
    }
    printf("%d",dp[n]);
}