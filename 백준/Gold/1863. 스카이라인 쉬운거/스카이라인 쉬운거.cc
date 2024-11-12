#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    map<int,vector<int>> ma;
    ma[0].push_back(0),ma[0].push_back(2e6);
    while(n--){
        int x,y;scanf("%d%d",&x,&y);
        ma[y].push_back(x);
    }
    set<int> se;
    int ans=0;
    for(auto [h,v]:ma){
        set<int> se2;
        if(h)for(auto i:v)se2.insert(*se.lower_bound(i));
        ans+=se2.size();
        for(auto i:v)se.insert(i);
    }
    printf("%d",ans);
}