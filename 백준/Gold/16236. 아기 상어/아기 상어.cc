#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
pii go[4]={{0,1},{0,-1},{1,0},{-1,0}};
int a[22][22];
vector<pii> v[8];
set<pii> fish;

int dist[22][22];

pii find_fish(){
    auto x=fish.begin();
    for(auto it=fish.begin();it!=fish.end();it++)
        if(dist[(*x).first][(*x).second] > dist[(*it).first][(*it).second])x=it;
        else if(dist[(*x).first][(*x).second]==dist[(*it).first][(*it).second]&&(*x)>(*it))x=it;
    pii ret=*x;
    fish.erase(x);
    return ret;
}

int main() {
    int n;scanf("%d",&n);
    pii shark;
    memset(a,0x3f,sizeof(a));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==9) shark={i,j}, a[i][j]=0;
            else v[a[i][j]].push_back({i,j});
        }
    int ans=0,eat=0,sz=2;
    while(!v[1].empty())fish.insert(v[1].back()),v[1].pop_back();
    while(!fish.empty()){
        memset(dist, 0x3f, sizeof(dist));
        dist[shark.first][shark.second]=0;
        queue<pii> q; q.push(shark);
        while(!q.empty()){
            pii cur=q.front();q.pop();
            for(auto i:go){
                int x=cur.first+i.first,y=cur.second+i.second;
                if(a[x][y]<=sz && dist[x][y] > 1e9)
                    dist[x][y]= dist[cur.first][cur.second] + 1,q.push({x, y});
            }
        }
        pii x=find_fish();
        if(dist[x.first][x.second]>1e9)break;
        ans+=dist[x.first][x.second];
        eat++;shark=x;
        if(eat==sz&&sz<7){
            sz++;eat=0;
            while(!v[sz-1].empty())
                fish.insert(v[sz-1].back()),v[sz-1].pop_back();
        }
    }
    printf("%d",ans);
    return 0;
}