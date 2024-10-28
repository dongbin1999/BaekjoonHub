#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> arr;
typedef pair<int,int> pii;
typedef long long ll;

int main(){
    int n,k;scanf("%d%d",&n,&k);
    vector<arr> v(n+1);
    for(int i=1;i<=n;i++)scanf("%d%d",&v[i][0],&v[i][1]),v[i][2]=i;
    sort(v.begin(),v.end());
    vector<pii> pos(2);pos[1]={v[1][2],0};
    int py=v[1][1];
    for(int i=2;i<=n;i++){
        auto [x,y,idx]=v[i];
        pos.push_back({idx,pos.back().second+max(0,x-py)});
        py=max(py,y);
    }
    vector<int> d(n+1);
    for(auto [x,y]:pos)d[x]=y;
    int cur=1;ll ans=0;
    while(k--){
        int nx;scanf("%d",&nx);
        ans+=abs(d[nx]-d[cur]);
        cur=nx;
    }
    printf("%lld",ans);
}