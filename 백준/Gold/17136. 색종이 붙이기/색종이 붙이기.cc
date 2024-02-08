#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int ans=1e9;
vector<vector<int>> b;
vector<int> p={0,5,5,5,5,5};

bool swap(int x,int y,int sz){
    if(x+sz-1>10||y+sz-1>10) return false;
    for(int i=x;i<=x+sz-1;i++)for(int j=y;j<=y+sz-1;j++)if(b[i][j]!=b[x][y])return false;
    for(int i=x;i<=x+sz-1;i++)for(int j=y;j<=y+sz-1;j++)b[i][j]=!b[i][j];
    return true;
}

void f(int x,int y,int depth){
    if(depth>=ans) return;
    if(y>10){
        f(x+1,0,depth);
        return;
    }
    if(x>10){
        ans=min(ans,depth);
        return;
    }
    vector<pii> v;
    if(!b[x][y]) f(x,y+1,depth);
    else
        for(int s=5;s>=1;s--)
            if(p[s]&&swap(x,y,s))
                p[s]--,f(x,y+1,depth+1),p[s]++,swap(x,y,s);
}

int main(){
    vector<int> t(11,0);
    b.assign(11,t);
    for(int i=1;i<=10;i++)for(int j=1;j<=10;j++)scanf("%d",&b[i][j]);
    f(1,1,0);
    printf("%d",ans==1e9?-1:ans);
    return 0;
}
