#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    unordered_map<ll,int> ma;
    vector<pii> v(n);
    for(auto &[x,y]:v)scanf("%d%d",&x,&y);
    for(auto [x,y]:v)for(auto [x2,y2]:v)
        ma[(ll)(x+x2)*4e9+y+y2]++;
    int ans=0;
    for(auto [a,b]:ma)ans=max(ans,b);
    printf("%d",ans);
    return 0;
}