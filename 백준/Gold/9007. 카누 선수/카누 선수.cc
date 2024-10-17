#include<bits/stdc++.h>
using namespace std;
void solve(){
    int k,n;scanf("%d%d",&k,&n);
    vector<vector<int>> v(4,vector<int>(n));
    for(int i=0;i<4;i++)for(int j=0;j<n;j++)scanf("%d",&v[i][j]);
    vector<int> a,b;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)a.push_back(v[0][i]+v[1][j]);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)b.push_back(v[2][i]+v[3][j]);
    sort(a.begin(),a.end()),sort(b.begin(),b.end());
    pair<int,int> ans={1e9,1e9};
    for(auto x:a){
        int idx=upper_bound(b.begin(),b.end(),k-x)-b.begin();
        if(idx<b.size()){
            int diff=abs(b[idx]+x-k);
            ans=min(ans,{diff,x+b[idx]});
        }
        idx--;
        if(idx>=0){
            int diff=abs(b[idx]+x-k);
            ans=min(ans,{diff,x+b[idx]});
        }
    }
    printf("%d\n",ans.second);
}
int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}