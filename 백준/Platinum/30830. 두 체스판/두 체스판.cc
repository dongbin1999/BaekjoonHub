#include <bits/stdc++.h>
using namespace std;
typedef array<int,3> arr;
typedef pair<int,int> pii;

vector<int> graph[200001];
int vis[200001];

int main(){
    int n;scanf("%d",&n);
    vector<arr> r(n+n+1);
    vector<vector<arr>> a(n+1),b(n+1);
    for(int i=1;i<=n+n;i++){
        int x,y;scanf("%d%d",&x,&y);
        r[i]={x,y,i};
        a[x].push_back(r[i]);
        b[y].push_back(r[i]);
        if(a[x].size()>2||b[y].size()>2)return !printf("-1");
    }
    for(int i=1;i<=n;i++){
        if(a[i].size()==2){
            auto [x1,y1,i1]=a[i][0];auto [x2,y2,i2]=a[i][1];
            graph[i1].push_back(i2),graph[i2].push_back(i1);
        }
        if(b[i].size()==2){
            auto [x1,y1,i1]=b[i][0];auto [x2,y2,i2]=b[i][1];
            graph[i1].push_back(i2),graph[i2].push_back(i1);
        }
    }
    int cnt=0;
    for(int i=1;i<=n+n;i++){
        if(vis[i])continue;
        queue<pii> q;
        q.push({i,0}),vis[i]=1;
        int tmp=0,tmp2=0;
        while(!q.empty()){
            auto [cur,c]=q.front();q.pop();
            tmp+=(cur<=n)==c,tmp2+=(cur<=n)!=c;
            for(auto nx:graph[cur]){
                if(vis[nx])continue;
                q.push({nx,c^1}),vis[nx]=1;
            }
        }
        cnt+=min(tmp,tmp2);
    }
    printf("%d",cnt/2);
    return 0;
}