#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> tup;
typedef pair<int,int> pii;

int u[1001];
int find(int x){
    return u[x]<0?x:u[x]=find(u[x]);
}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return false;
    u[a]+=u[b],u[b]=a;
    return true;
}
int main(){
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    vector<tup> e(m);
    for(int i=1;i<=m;i++){
        int a,b;scanf("%d%d",&a,&b);
        e[i-1]={a,b,i};
    }
    vector<bool> v(m);
    while(k--){
        memset(u,-1,sizeof(u));
        int cost=0;
        pii edge={1e9,1e9};
        for(int i=0;i<m;i++){
            if(v[i])continue;
            auto [a,b,c]=e[i];
            if(merge(a,b))cost+=c,edge=min(edge,{c,i});
            if(u[find(1)]==-n)break;
        }
        if(u[find(1)]==-n){
            printf("%d ",cost);
            if(edge.second<1e9)v[edge.second]=1;
        }
        else printf("0 ");
    }
}