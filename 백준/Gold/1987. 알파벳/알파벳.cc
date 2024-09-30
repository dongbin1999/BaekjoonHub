#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii go[4]={{0,1},{0,-1},{1,0},{-1,0}};
char s[33][33];
int ans,n,m;
void dfs(int x,int y,bitset<26> al){
    ans=max(ans,(int)al.count());
    for(auto [dx,dy]:go){
        int nx=x+dx,ny=y+dy;
        if(nx<1||nx>n||ny<1||ny>m)continue;
        if(al[s[nx][ny]-'A'])continue;
        al[s[nx][ny]-'A']=1;
        dfs(nx,ny,al);
        al[s[nx][ny]-'A']=0;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    bitset<26> al;
    al[s[1][1]-'A']=1;
    dfs(1,1,al);
    printf("%d",ans);
    return 0;
}