#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> f={1,1};
set<ll> se[4];
void solve(){
    ll a,b;scanf("%lld%lld",&a,&b);
    printf(se[a].count(b)?"YES\n":"NO\n");
}

int main(){
    while(f.back()<1e16)f.push_back(f[f.size()-2]+f[f.size()-1]);
    for(auto a:f){
        se[1].insert(a);
        for(auto b:f){
            se[2].insert(a+b);
            for(auto c:f)
                se[3].insert(a+b+c);
        }
    }
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}