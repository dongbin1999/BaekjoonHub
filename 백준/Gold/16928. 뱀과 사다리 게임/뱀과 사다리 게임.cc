#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int a[101],vis[101];
int main(){
    int n,m;scanf("%d%d",&n,&m);
    n+=m;
    while(n--){
        int x,y;scanf("%d%d",&x,&y);
        if(x>=1&&x<=100)a[x]=y;
    }
    queue<pii> q;vis[1]=1,q.push({1,0});
    while(!q.empty()){
        auto [x,turn]=q.front();q.pop();
        if(x==100)return !printf("%d",turn);
        for(int i=x+1;i<=min(100,x+6);i++){
            int y=i;while(a[y]>=1&&a[y]<=100)y=a[y];
            if(y>=1&&y<=100&&!vis[y])vis[y]=1,q.push({y,turn+1});
        }
    }
    return 0;
}