#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)scanf("%d",&v[i]);
    pii ans={0,0};
    for(int i=1;i<=n;i++){
        vector<int> vis(n+1);
        int x=i;vis[x]=1;
        while(1){
            x=v[x];
            if(vis[x])break;
            vis[x]=1;
        }
        ans=max(ans,{accumulate(vis.begin(),vis.end(),0),-i});
    }
    printf("%d",-ans.second);
    return 0;
}