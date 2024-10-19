#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

pii p[3001];
unordered_set<int> se[20001];

bool f(int x,int y){
    if(x<-10000||x>10000)return 0;
    return se[x+10000].count(y);
}

void solve(){
    int n;scanf("%d",&n);
    for(int i=0;i<=20000;i++)se[i].clear();
    for(int i=0;i<n;i++)scanf("%d%d",&p[i].first,&p[i].second),se[p[i].first+10000].insert(p[i].second);
    int ans=0;
    for(int a=0;a<n;a++)for(int b=a+1;b<n;b++){
        int dx=p[a].first-p[b].first,dy=p[a].second-p[b].second;
        if(ans>=dx*dx+dy*dy)continue;
        int ax=p[a].first+dy,ay=p[a].second-dx;
        int bx=p[b].first+dy,by=p[b].second-dx;
        if(f(ax,ay)&&f(bx,by)){
            ans=max(ans,dx*dx+dy*dy);
            continue;
        }
        ax=p[a].first-dy,ay=p[a].second+dx;
        bx=p[b].first-dy,by=p[b].second+dx;
        if(f(ax,ay)&&f(bx,by))ans=max(ans,dx*dx+dy*dy);
    }
    printf("%d\n",ans);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}