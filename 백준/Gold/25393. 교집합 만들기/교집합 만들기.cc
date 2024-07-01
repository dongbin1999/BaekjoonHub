#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int l[1000001],r[1000001];
set<pii> se;

int main(){
    int n;scanf("%d",&n);
    memset(r,0x3f,sizeof(r));
    while(n--){
        int x,y;scanf("%d%d",&x,&y);
        se.insert({x,y}),l[x]=max(l[x],y),r[y]=min(r[y],x);
    }
    int q;scanf("%d",&q);
    while(q--){
        int x,y;scanf("%d%d",&x,&y);
        if(se.count({x,y}))printf("1\n");
        else if(r[y]<=x&&l[x]>=y)printf("2\n");
        else printf("-1\n");
    }
}