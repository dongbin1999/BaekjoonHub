#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,pii> coin;
#define x first
#define y second
#define in(c) (c.x>=0&&c.x<n&&c.y>=0&&c.y<m)
pii go[4]={{0,1},{0,-1},{1,0},{-1,0}};
char s[100][100];
int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<pii> p;
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
        for(int j=0;j<m;j++)
            if(s[i][j]=='o')p.push_back({i,j});
    }
    set<coin> se;
    queue<pair<coin,int>> q;
    q.push({{p[0],p[1]},0}),se.insert({p[0],p[1]});
    while(!q.empty()){
        auto [c,dist]=q.front();q.pop();
        auto [a,b]=c;
        for(auto [dx,dy]:go){
            pii c1=a,c2=b;
            c1.x+=dx,c1.y+=dy,c2.x+=dx,c2.y+=dy;
            if(s[c1.x][c1.y]=='#')c1.x-=dx,c1.y-=dy;
            if(s[c2.x][c2.y]=='#')c2.x-=dx,c2.y-=dy;
            if(in(c1)&&in(c2)&&!se.count({c1,c2}))
                se.insert({c1,c2}),q.push({{c1,c2},dist+1});
            else if(in(c1)^in(c2))return !printf("%d",dist+1);
        }
    }
    printf("-1");
    return 0;
}