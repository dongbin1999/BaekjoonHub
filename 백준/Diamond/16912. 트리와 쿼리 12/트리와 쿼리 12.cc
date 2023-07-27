#include<bits/stdc++.h>
using namespace std;
const int sz=1<<17;
typedef pair<int,int> pii;

vector<vector<pii>> edges(sz*2);
void update(int s,int e,pii edge,int node,int ns,int ne){
    if(e<ns||ne<s)return;
    if(s<=ns&&ne<=e){
        edges[node].push_back(edge);
        return;
    }
    int mid=(ns+ne)/2;
    update(s,e,edge,node*2,ns,mid),update(s,e,edge,node*2+1,mid+1,ne);
}void update(int s,int e,pii edge){update(s,e,edge,1,0,sz-1);}

stack<vector<int>> rollback;
int u[sz*2];
int find(int x){return u[x]<0?x:find(u[x]);}
bool merge(int a,int b,int node){
    a=find(a),b=find(b);
    if(a==b)return false;
    if(-u[a]<-u[b])swap(a,b);
    rollback.push({node,a,u[a],b,u[b]});
    if(u[a]==u[b])u[a]--;
    u[b]=a;
    return true;
}

vector<pii> v;
int _clock;
void divide(int node,int ns,int ne){
    for(auto [a,b]:edges[node])merge(a,b,node);
    if(ns==ne&&ns<_clock){
        auto [a,b]=v[ns];
        printf("%d\n",find(a)==find(b));
    }
    if(ns<ne){
        int mid=(ns+ne)/2;
        divide(node*2,ns,mid),divide(node*2+1,mid+1,ne);
    }
    while(!rollback.empty()&&rollback.top()[0]==node){
        vector<int> a=rollback.top();rollback.pop();
        u[a[1]]=a[2],u[a[3]]=a[4];
    }
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    memset(u,-1,sizeof(u));
    map<pii,int> start;
    for(int i=0;i<m;i++){
        int c,a,b;scanf("%d%d%d",&c,&a,&b);
        if(a>b)swap(a,b);
        if(c==1)start[{a,b}]=_clock;
        else if(c==2)update(start[{a,b}],_clock-1,{a,b}),start[{a,b}]=-1;
        else v.push_back({a,b}),_clock++;
    }
    for(auto [edge,st]:start)
        if(st!=-1)update(st,_clock,edge);
    divide(1,0,sz-1);
    return 0;
}