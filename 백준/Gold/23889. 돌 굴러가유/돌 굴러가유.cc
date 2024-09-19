#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    vector<int> v(n+1),sum(n+1);
    for(int i=1;i<=n;i++)scanf("%d",&v[i]),sum[i]=sum[i-1]+v[i];
    vector<pair<int,int>> vv;
    vector<int> a(k+1);
    for(int i=1;i<=k;i++)scanf("%d",&a[i]);
    for(int i=1;i<k;i++)vv.push_back({sum[a[i+1]-1]-sum[a[i]-1],-a[i]});
    vv.push_back({sum[n]-sum[a[k]-1],-a[k]});
    sort(vv.begin(),vv.end(),greater<pair<int,int>>());
    vector<int> ans;
    for(int i=0;i<m;i++)ans.push_back(-vv[i].second);
    sort(ans.begin(),ans.end());
    for(auto i:ans)printf("%d\n",i);
}