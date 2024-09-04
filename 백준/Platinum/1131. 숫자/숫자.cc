#include<bits/stdc++.h>
using namespace std;

int dp[4000001];

int k;
int f(int x){
    int ret=0;
    while(x){
        int y=x%10,z=1;
        x/=10;
        for(int i=0;i<k;i++)z*=y;
        ret+=z;
    }
    return ret;
}

int main(){
    int a,b;scanf("%d%d%d",&a,&b,&k);
    long long ans=0;
    memset(dp,-1,sizeof(dp));
    for(int i=a;i<=b;i++){
        vector<int> x;
        map<int,int> ma;
        int z=i;
        while(dp[z]==-1&&!ma.count(z)){
            ma[z]=x.size();
            x.push_back(z);
            z=f(z);
        }
        if(ma.count(z)){//이번에 처음 구한 사이클
            int j=ma[z],mn=1e9;
            for(int n=j;n<x.size();n++)mn=min(mn,x[n]);
            for(int n=j;n<x.size();n++)dp[x[n]]=mn;
            for(int n=j-1;n>=0;n--){
                mn=min(mn,x[n]);
                dp[x[n]]=mn;
            }
        }
        else{//원래 있던 사이클
            int mn=dp[z];
            for(int n=x.size()-1;n>=0;n--){
                mn=min(mn,x[n]);
                dp[x[n]]=mn;
            }
        }
        ans+=dp[i];
    }
    printf("%lld",ans);
    return 0;
}