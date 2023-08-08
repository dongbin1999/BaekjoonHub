#include <bits/stdc++.h>
using namespace std;
const int sz=100000;

vector<int> tree[sz+1],centroid_tree[sz+1];
int sub[sz+1],centroid_pa[sz+1];
bool removed[sz+1];
int get_subsize(int node,int pa=-1){
    sub[node]=1;
    for(auto nx:tree[node])
        if(nx!=pa&&!removed[nx]) sub[node]+=get_subsize(nx,node);
    return sub[node];
}
int get_centroid(int node,int fsz,int pa=-1){
    for(auto nx:tree[node])
        if(nx!=pa&&sub[nx]*2>fsz&&!removed[nx]) return get_centroid(nx,fsz,node);
    return node;
}
void make_centroid_tree(int node=1,int pre=-1){
    int centroid=get_centroid(node,get_subsize(node));
    removed[centroid]=1;
    centroid_pa[centroid]=pre;
    centroid_tree[pre].push_back(centroid);
    centroid_tree[centroid].push_back(pre);
    for(auto nx:tree[centroid])
        if(!removed[nx]) make_centroid_tree(nx,centroid);
}

int depth[sz+1],sparse[17][sz+1];
void LCA_init(int node=1,int d=0,int pa=1){
    depth[node]=d,sparse[0][node]=pa;
    for(int i=1;i<17;i++)
        sparse[i][node]=sparse[i-1][sparse[i-1][node]];
    for(int nx:tree[node])
        if(pa!=nx)LCA_init(nx,d+1,node);
}
int dist(int a,int b){
    if(depth[a]>depth[b])swap(a,b);
    int aa=a,bb=b;
    for(int i=16;i>=0;i--)
        if(depth[sparse[i][b]]>=depth[a])
            b=sparse[i][b];
    if(a==b)return depth[bb]-depth[a];
    for(int i=16;i>=0;i--)
        if(sparse[i][a]!=sparse[i][b])
            a=sparse[i][a],b=sparse[i][b];
    int lca=sparse[0][a];
    return depth[aa]+depth[bb]-depth[lca]*2;
}

bool color[sz+1];
multiset<int> se[sz+1];
void change(int node){
    color[node]^=1;
    int go=node;
    while(go!=-1){
        if(color[node])se[go].insert(dist(go,node));
        else se[go].erase(se[go].find(dist(go,node)));
        go=centroid_pa[go];
    }
}
void ans(int node){
    int go=node,ret=1e9;
    while(go!=-1){
        if(!se[go].empty())ret=min(ret,dist(go,node)+*se[go].begin());
        go=centroid_pa[go];
    }
    printf("%d\n",ret==1e9?-1:ret);
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    make_centroid_tree();
    LCA_init();
    int m;scanf("%d",&m);
    while(m--){
        int a,b;scanf("%d%d",&a,&b);
        (a==1?change:ans)(b);
    }
    return 0;
}