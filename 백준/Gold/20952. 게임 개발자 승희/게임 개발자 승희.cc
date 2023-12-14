#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<vector<pll>> v(7);
vector<ll> del(7);

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        ll x;scanf("%lld",&x);
        v[x%7].push_back({x,i});
    }
    for(int i=0;i<7;i++)if(v[i].empty())del[i]=1;
    ll add=0;
    while(m--){
        ll x;scanf("%lld",&x);
        add+=x;
        vector<ll> b=del;
        del[(7-add%7)%7]=1;
        if(*min_element(del.begin(),del.end()))
            add-=x,del=b;
    }
    vector<pll> ans;
    for(int i=0;i<7;i++){
        if(del[i])continue;
        for(auto j:v[i])ans.push_back({j.second,j.first+add});
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(auto i:ans)printf("%lld ",i.second%1000000007);
    return 0;
}