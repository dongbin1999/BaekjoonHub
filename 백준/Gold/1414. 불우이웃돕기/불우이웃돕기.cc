#include<bits/stdc++.h>
using namespace std;
typedef array<int,3> tup;
int u[500];
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return 0;
    if(-u[x]<-u[y])swap(x,y);
    u[x]+=u[y],u[y]=x;
    return 1;
}

int main(){
    memset(u,-1,sizeof(u));
    unordered_map<char,int> ma;
    for(int i='a';i<='z';i++)ma[i]=i-'a'+1;
    for(int i='A';i<='Z';i++)ma[i]=i-'A'+27;
    ma['0']=0;
    priority_queue<tup,vector<tup>,greater<tup>> pq;
    int ans=0;
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        char c;scanf(" %c",&c);
        if(ma[c])pq.push({ma[c],i,j}),ans+=ma[c];
    }
    while(!pq.empty()){
        auto [c,x,y]=pq.top();pq.pop();
        if(merge(x,y))ans-=c;
    }
    if(u[find(1)]!=-n)return !printf("-1");
    printf("%d",ans);
}