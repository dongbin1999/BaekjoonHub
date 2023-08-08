#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<pii> tree[200001];
int sub[200001];
bool removed[200001];
int get_subsize(int node,int pa=-1){
    sub[node]=1;
    for(auto [nx,cost]:tree[node])
        if(nx!=pa&&!removed[nx]) sub[node]+=get_subsize(nx,node);
    return sub[node];
}
int get_centroid(int node,int sz,int pa=-1){
    for(auto [nx,cost]:tree[node])
        if(nx!=pa&&sub[nx]*2>sz&&!removed[nx]) return get_centroid(nx,sz,node);
    return node;
}

map<int,int> ma;
int k,ans=1e9;
vector<pii> get_path(int node,int pa,int dist,int depth){
    vector<pii> path={{dist,depth}};
    for(auto [nx,cost]:tree[node])
        if(nx!=pa&&!removed[nx])
            for(auto p:get_path(nx,node,dist+cost,depth+1))
                path.push_back(p);
    return path;
}

void dnc(int root){
    int centroid=get_centroid(root,get_subsize(root));
    removed[centroid]=1;

    ma.clear();
    for(auto [nx,cost]:tree[centroid])
        if(!removed[nx]) {
            vector<pii> path=get_path(nx,centroid,cost,1);
            for(auto [dist,depth]:path){
                if(dist==k)ans=min(ans,depth);
                else if(ma.find(k-dist)!=ma.end())
                    ans=min(ans,depth+ma[k-dist]);
            }
            for(auto [dist,depth]:path)
                if(dist<k){
                    if(ma.find(dist)==ma.end())ma[dist]=depth;
                    else ma[dist]=min(ma[dist],depth);
                }
        }
    for(auto [nx,cost]:tree[centroid])
        if(!removed[nx]) dnc(nx);
}

int main(){
    int n;scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int a,b,l;scanf("%d%d%d",&a,&b,&l);
        tree[a].push_back({b,l});
        tree[b].push_back({a,l});
    }
    dnc(0);
    printf("%d",ans==1e9?-1:ans);
    return 0;
}