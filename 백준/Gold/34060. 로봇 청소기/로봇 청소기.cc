#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int u[200001];
pii go[4]={{0,1},{0,-1},{1,0},{-1,0}};
int find(int x){return u[x]<0?x:u[x]=find(u[x]);}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return 0;
    u[a]+=u[b],u[b]=a;
    return 1;
}

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(auto &x:v)scanf("%d",&x);
    int ans=0,X=0;
    map<pii,int> ma;vector<pii> p;
    for(int i=0;i<n;i++){
        if(!i||v[i-1]>=v[i])X++;
        p.push_back({X,v[i]});
        ma[p.back()]=i;
    }
    memset(u,-1,sizeof(u));
    for(auto [x,y]:p)
        for(auto [dx,dy]:go){
            int nx=x+dx,ny=y+dy;
            if(ma.count({nx,ny}))merge(ma[{x,y}],ma[{nx,ny}]);
        }
    for(int i=0;i<n;i++)if(find(i)==i)ans++;
    printf("%d\n%d",ans,n);
}