#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
void solve(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    map<int,vector<int>> ma;
    for(int i=0;i<n;i++)scanf("%d",&v[i]),ma[v[i]].push_back(i+1);
    if(ma.size()==1){
        printf("NO\n");
        return;
    }
    printf("YES\n");
    vector<int> ans(n+1);
    for(auto it=ma.begin();it!=ma.end();it++){
        int x=it->first;
        int y;
        if(next(it)==ma.end())
            y=ma.begin()->second.back();
        else y=next(it)->second.back();
        ans[x]=y;
    }
    vector<int> x;
    for(auto [a,b]:ma){
        b.pop_back();
        while(!b.empty())x.push_back(b.back()),b.pop_back();
    }
    for(int i=1;i<=n;i++)if(!ans[i])ans[i]=x.back(),x.pop_back();
    vector<pii> vv;
    for(int i=1;i<=n;i++)vv.push_back({ans[i],i});
    sort(vv.begin(),vv.end());
    for(auto [a,b]:vv)printf("%d ",b);
    printf("\n");
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}