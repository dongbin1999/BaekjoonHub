#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<int> tree[5001];
int mn[5001],mx[5001];
bool c[5001],e[5001][5001];

vector<pii> merge(vector<pii> a,vector<pii> b){
    vector<pii> ret(a.size()+b.size()-1,{1e9,-1e9});
    for(int i=0;i<a.size();i++)for(int j=0;j<b.size();j++){
        auto [amn,amx]=a[i];auto [bmn,bmx]=b[j];
        ret[i+j].first=min(ret[i+j].first,amn+bmn),ret[i+j].second=max(ret[i+j].second,amx+bmx);
    }
    return ret;
}

vector<pii> go(int node=1,int pa=-1){
    vector<pii> ret={{0,0}};
    for(auto nx:tree[node]){
        if(nx==pa)continue;
        if(ret.size()==1)ret=go(nx,node);
        else ret=merge(ret,go(nx,node));
    }
    reverse(ret.begin(),ret.end());
    ret.push_back({0,0});
    reverse(ret.begin(),ret.end());
    if(c[node])for(int i=1;i<ret.size();i++)ret[i].first++,ret[i].second++;
    for(int i=0;i<ret.size();i++)mn[i]=min(mn[i],ret[i].first),mx[i]=max(mx[i],ret[i].second);
    return ret;
}

int main(){
    int n,b;scanf("%d%d",&n,&b);
    while(b--){
        int x;scanf("%d",&x);
        c[x]=1;
    }
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        tree[u].push_back(v),tree[v].push_back(u);
    }
    memset(mn,0x3f,sizeof(mn)),memset(mx,-0x3f,sizeof(mx));
    vector<pii> v=go();
    for(int i=0;i<v.size();i++)
        for(int j=mn[i];j<=mx[i];j++)e[i][j]=1;

    int q,ans=0;scanf("%d",&q);
    while(q--){
        int i,j;scanf("%d%d",&i,&j);
        ans+=e[i][j];
    }
    printf("%d",ans);
}