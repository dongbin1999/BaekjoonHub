#include<bits/stdc++.h>
using namespace std;
int u[4001];
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
int merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return 0;
    u[a]+=u[b],u[b]=a;
    return 1;
}
int main(){
    int n,m;scanf("%d%d",&n,&m);
    memset(u,-1,sizeof(u));
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        if(find(x)==find(y))return !printf("0");
        merge(x,y+n),merge(x+n,y);
    }
    printf("1");
}