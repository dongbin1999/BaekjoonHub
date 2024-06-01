#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100001],rev[100001];
int v[100001];

int main(){
    int n,m,x;scanf("%d%d%d",&n,&m,&x);
    while(m--){
        int a,b;scanf("%d%d",&a,&b);
        graph[a].push_back(b),rev[b].push_back(a);
    }
    int X=0,Y=0;
    queue<int> q;q.push(x),X++,v[x]=1;
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(auto nx:graph[cur])
            if(!v[nx])v[nx]=1,q.push(nx),X++;
    }
    memset(v,0,sizeof(v));
    q.push(x),Y++,v[x]=1;
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(auto nx:rev[cur])
            if(!v[nx])v[nx]=1,q.push(nx),Y++;
    }
    printf("%d %d",Y,n-X+1);
    return 0;
}