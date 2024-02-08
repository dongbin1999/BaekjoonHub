#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
void solve(){
    int n;scanf("%d",&n);
    vector<int> h(n+1),d(n+1),sum(n+1),latelmx(n+1),latermx(n+2);
    vector<pii> dh;
    for(int i=1;i<=n;i++)scanf("%d",&h[i]);
    for(int i=1;i<=n;i++)scanf("%d",&d[i]),dh.push_back({d[i],h[i]});
    sort(dh.begin(),dh.end());
    for(int i=1;i<=n;i++){
        auto[x,y]=dh[i-1];
        h[i]=y,d[i]=x;
    }
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+h[i],
    latelmx[i]=max(latelmx[i-1],sum[i]-d[i]);
    for(int i=n;i>=1;i--)latermx[i]=max(latermx[i+1],sum[i]-d[i]);
    int ans=1e9;
    for(int i=1;i<=n;i++)ans=min(ans,max(latelmx[i-1],latermx[i]-h[i]+1));
    printf("%d\n",ans);
}

int main() {
    int t;scanf("%d",&t);
    while(t--)solve();
}