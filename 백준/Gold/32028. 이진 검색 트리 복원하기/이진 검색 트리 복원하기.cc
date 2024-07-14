#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef array<int,4> arr;

vector<pii> v[200002];
int ans[200002][2];
queue<arr> q[200002];

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,d;scanf("%d%d",&a,&d);
        v[d].push_back({a,i});
    }
    memset(ans,-1,sizeof(ans));
    for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end());
    if(v[1].size()>1)return !printf("-1");
    for(int i=2;i<=n;i++)
        if(v[i].size()>v[i-1].size()*2)return !printf("-1");
    q[2].push({-2000000000,v[1][0].first-1,v[1][0].second,0}),
    q[2].push({v[1][0].first+1,2000000000,v[1][0].second,1});
    for(int d=2;d<=n;d++){
        if(v[d].empty())continue;
        for(auto [a,i]:v[d]){
            bool ok=0;
            while(!q[d].empty()){
                auto [pl,pr,pi,plr]=q[d].front();q[d].pop();
                if(pl<=a&&a<=pr){
                    q[d+1].push({pl,a-1,i,0}),q[d+1].push({a+1,pr,i,1}),
                    ans[pi][plr]=i,ok=1;
                    break;
                }
                else continue;
            }
            if(!ok)return !printf("-1");
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d %d\n",ans[i][0],ans[i][1]);
    return 0;
}