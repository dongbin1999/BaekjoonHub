#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii dp[101][101][51];
int a[101],mx;
vector<pii> v;
void back(int l,int r){
    if(l>=r)return;
    pii ans={1e9,1e9};
    for(int h=1;h<=mx;h++)ans=min(ans,dp[l][r][h]);
    auto [c,m]=ans;
    if(m==r){
        v.push_back({l,r});
        back(l+1,r-1);
    }
    else{
        back(l,m),back(m+1,r);
    }
}


int main(){
    int n;scanf("%d",&n);
    mx=n/2;
    for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<n;i++)if(a[i]^a[i+1])dp[i][i+1][1]={3,i+1};
    for(int len=2;len<=n;len+=2)for(int l=1,r=l+len-1;r<=n;l++,r++){
        for(int h=1;h<=mx;h++){
            dp[l][r][h]=min(dp[l][r][h],dp[l][r][h-1]);
            for(int m=l+1;m+1<=r-1;m+=2){
                auto [lc,lr]=dp[l][m][h];
                auto [rc,rr]=dp[m+1][r][h];
                dp[l][r][h]=min(dp[l][r][h],{lc+rc,m});
            }
        }
        if(a[l]==a[r])continue;
        for(int h=2;h<=mx;h++){
            auto [c,m]=dp[l+1][r-1][h-1];
            for(int H=h;H<=mx;H++)dp[l][r][H]=min(dp[l][r][H],{c+len-1+h*2,r});
        }
    }
    pii ans={1e9,1e9};
    for(int h=1;h<=mx;h++)ans=min(ans,dp[1][n][h]);
    printf("%d\n",ans.first);
    back(1,n);
    sort(v.begin(),v.end());
    for(auto [l,r]:v)printf("%d %d\n",l,r);
}