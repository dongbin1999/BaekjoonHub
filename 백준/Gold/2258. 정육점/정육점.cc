#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;scanf("%d%d",&n,&m);
    map<int,vector<int>> ma;
    while(n--){
        int x,y;scanf("%d%d",&x,&y);
        ma[y].push_back(x);
    }
    for(auto &[x,y]:ma)sort(y.begin(),y.end(),greater<int>());
    int sum=0,price;long long ans=2e18;
    for(auto [x,y]:ma){
        price=0;
        for(auto i:y){
            price+=x,sum+=i;
            if(sum>=m)ans=min(ans,(long long)price);
        }
    }
    printf("%lld",ans==2e18?-1:ans);
}