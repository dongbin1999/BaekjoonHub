#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int a[101],vis[101];
int main(){
    int n,m;scanf("%d%d",&n,&m);
    n+=m;
    while(n--){
        int x,y;scanf("%d%d",&x,&y);
        a[x]=y;
    }
    queue<pii> q;vis[1]=1,q.push({1,0});
    while(!q.empty()){
        auto [x,turn]=q.front();q.pop();
        if(x==100)return !printf("%d",turn);
        for(int i=x+1;i<=min(100,x+6);i++){
            int y=i;while(a[y])y=a[y];
            if(!vis[y])vis[y]=1,q.push({y,turn+1});
        }
    }
    return 0;
}