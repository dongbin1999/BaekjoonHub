#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<int> graph[200001];
int a[200001],ans[200001],b[200001];

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        while(1){
            int x;scanf("%d",&x);
            if(!x)break;
            graph[i].push_back(x);
        }
    }
    int m;scanf("%d",&m);
    memset(ans,-1,sizeof(ans));
    queue<pii> q;
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]),ans[a[i]]=0;
        q.push({a[i],0});
    }
    while(!q.empty()){
        auto [cur,t]=q.front();q.pop();
        for(auto nx:graph[cur]){
            b[nx]++;
            if(ans[nx]==-1&&b[nx]*2>=graph[nx].size())
                q.push({nx,t+1}),ans[nx]=t+1;
        }
    }
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}