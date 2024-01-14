#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

void solve(){
    int n;scanf("%d",&n);
    vector<pii> ans;
    for(int i=(n+2)/3,j=(n+2)/3;j>=1;i++,j--)ans.push_back({i,j});
    for(int i=n,j=ans.begin()->second+1+(n%3==2);i>j;i--,j++)ans.push_back({i,j});
    assert(ans.size()==(2*n+1)/3);
    printf("%d\n",ans.size());
    for(auto [i,j]:ans)printf("%d %d\n",i,j);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}