#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> arr;
arr dp[151][151];
int main(){
    string a,b,c;cin>>a>>b>>c;
    memset(dp,-1,sizeof(dp));
    dp[0][0]={1000,-1,-1};
    for(int i=0;i<c.size();i++){
        for(int x=0,y=i;x<=a.size()&&y>=0;x++,y--){
            if(y>b.size())continue;
            if(dp[x][y][0]==-1)continue;
            if(x<a.size()&&a[x]==c[i])dp[x+1][y]={1,x,y};
            if(y<b.size()&&b[y]==c[i])dp[x][y+1]={2,x,y};
        }
    }
    string ans;
    arr cur=dp[a.size()][b.size()];
    while(cur[0]<3){
        auto [d,x,y]=cur;
        ans+=d+'0';
        cur=dp[x][y];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}