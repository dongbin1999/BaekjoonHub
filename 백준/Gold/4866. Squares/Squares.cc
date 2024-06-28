#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
void solve(){
    int n;scanf("%d",&n);
    if(!n)exit(0);
    int ans=0;
    set<pii> se;
    vector<pii> v(n);
    for(auto &[x,y]:v)scanf("%d%d",&x,&y),se.insert({x,y});
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
        int dx=v[j].first-v[i].first,dy=v[j].second-v[i].second;
        auto [x,y]=v[i];
        pii a={x+dy,y-dx},b={x+dy+dx,y-dx+dy};
        if(se.count(a)&&se.count(b))ans++;
        a={x-dy,y+dx},b={x-dy+dx,y+dx+dy};
        if(se.count(a)&&se.count(b))ans++;
    }
    printf("%d\n",ans/4);
}
int main(){
    while(1)solve();
}