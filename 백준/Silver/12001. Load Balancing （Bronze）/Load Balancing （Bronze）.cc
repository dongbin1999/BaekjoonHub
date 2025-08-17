#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int f(int x,int y,vector<pii> &v){
    vector<int> r(4);
    for(auto [a,b]:v)r[(a<x)<<1|(b<y)]++;
    return *max_element(r.begin(),r.end());
}
int main(){
    int n,b;scanf("%d%d",&n,&b);
    vector<pii> v(n);
    for(auto &[x,y]:v)scanf("%d%d",&x,&y);
    int ans=1e9;
    set<int> r,c;
    for(auto [x,y]:v)r.insert(x-1),r.insert(x+1),c.insert(y-1),c.insert(y+1);
    for(auto x:r)for(auto y:c)ans=min(ans,f(x,y,v));
    printf("%d",ans);
}