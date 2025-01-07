#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n,m;scanf("%d%d",&n,&m);
    pii ans={1e9,-1};
    vector<vector<int>> v(n,vector<int>(m));
    vector<int> sum(m);
    for(int i=0;i<n;i++){
        char c;scanf(" %c",&c);
        for(int j=0;j<m;j++){
            scanf("%1d",&v[i][j]);
            if(c=='L')v[i][j]*=-1;
            sum[j]+=v[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int mx=0,c=0;
        for(int j=0;j<m;j++)c+=sum[j]-v[i][j],mx=max(mx,abs(c));
        ans=min(ans,{mx,i+1});
    }
    printf("%d\n%d",ans.second,ans.first);
}