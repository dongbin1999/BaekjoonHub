#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    vector<array<int,4>> kk(k);
    for(auto &[x1,y1,x2,y2]:kk)
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    for(int i=0;i<kk.size();i++)for(int j=i+1;j<kk.size();j++){
        auto [ax1,ay1,ax2,ay2]=kk[i];
        auto [bx1,by1,bx2,by2]=kk[j];
        if(ax2<=bx1||bx2<=ax1||ay2<=by1||by2<=ay1)continue;
        printf("NONDISJOINT\n");return;
    }
    int sz=0;
    for(auto [x1,y1,x2,y2]:kk){
        if(x1<0||x1>n){printf("NONCONTAINED\n");return;}
        if(x2<0||x2>n){printf("NONCONTAINED\n");return;}
        if(y1<0||y1>m){printf("NONCONTAINED\n");return;}
        if(y2<0||y2>m){printf("NONCONTAINED\n");return;}
        sz+=(x2-x1)*(y2-y1);
    }
    if(sz!=n*m){printf("NONCOVERING\n");return;}
    printf("OK\n");
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}