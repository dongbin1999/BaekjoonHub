#include <bits/stdc++.h>
using namespace std;

int a[101],b[101];
bool vis[101];
vector<int> graph[101];

bool BM(int cur){
    vis[cur]=1;
    for(int go:graph[cur])
        if(b[go]==-1||!vis[b[go]]&&BM(b[go])){
            a[cur]=go,b[go]=cur;
            return 1;
        }
    return 0;
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    int xx=(n+1)/2,xy=n/2;
    fill(a,a+xx,-1),fill(b,b+xy,-1);

    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        if(x%2==y%2)continue;
        if(y%2)swap(x,y);
        graph[x/2].push_back(y/2-1);
    }

    int ans=0;
    for(int i=0;i<xx;i++){
        fill(vis,vis+xx,0);
        ans+=BM(i)*2;
    }
    printf("%d",ans+(ans<n));
    return 0;
}