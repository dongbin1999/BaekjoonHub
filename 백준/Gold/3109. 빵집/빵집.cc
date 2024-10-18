#include<bits/stdc++.h>
using namespace std;

char a[10002][502];
int r,c,ans,vis[10002][502];
vector<int> path;

bool b;
void go(int x){
    if(vis[x][path.size()])return;
    vis[x][path.size()]=1;
    if(b)return;
    if(path.size()==c){
        ans++,b=1;
        for(int i=0;i<c;i++)a[path[i]][i]='x';
        return;
    }
    for(int nx=x-1,ny=path.size();nx<=x+1;nx++){
        if(b||a[nx][ny]!='.')continue;
        path.push_back(nx);
        go(nx);
        path.pop_back();
    }
}

int main(){
    scanf("%d%d",&r,&c);
    for(int i=1;i<=r;i++)scanf("%s",a[i]);
    for(int i=1;i<=r;i++)b=0,path={i},go(i);
    printf("%d",ans);
}