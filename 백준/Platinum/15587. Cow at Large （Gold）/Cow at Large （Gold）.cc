#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<int> tree[100001];
pii go(int node,int pa=-1,int d=0){
    int cnt=0,mn=1e9;
    for(auto nx:tree[node]){
        if(nx==pa)continue;
        auto [cc,cl]=go(nx,node,d+1);
        cnt+=cc,mn=min(mn,cl);
    }
    if(mn==1e9)return {1,1};
    if(d>=mn)return {1,mn+1};
    else return {cnt,mn+1};
}


int main(){
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        tree[a].push_back(b),tree[b].push_back(a);
    }
    printf("%d",go(k).first);
    return 0;
}