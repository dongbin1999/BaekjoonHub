#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int cnt(vector<pii> &v,pii p,int l){
    auto [bx,by]=p;
    int ret=0;
    for(auto [x,y]:v)
        ret+=bx<=x&&x<=bx+l&&by<=y&&y<=by+l;
    return ret;
}

int main(){
    int n,m,l,k;scanf("%d%d%d%d",&n,&m,&l,&k);
    int ans=1e9;
    vector<pii> v(k);
    for(int i=0;i<k;i++)scanf("%d%d",&v[i].first,&v[i].second);
    for(auto [ax,ay]:v)
        for(auto [bx,by]:v)
            ans=min(ans,k-cnt(v,{ax,by},l));
    printf("%d",ans);
    return 0;
}