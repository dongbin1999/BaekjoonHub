#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
vector<int> tree[363636];
vector<int> go(int node=1,int pa=-1){
    vector<int> v={node};
    for(auto nx:tree[node]){
        if(nx==pa)continue;
        for(auto ch:go(nx,node))v.push_back(ch);
        if(v.size()>3){printf("U");exit(0);}
    }
    if(v.size()==3){
        ans.push_back(v);
        return {};
    }
    else return v;
}
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        tree[x].push_back(y),tree[y].push_back(x);
    }
    go();
    if(n/3!=ans.size())return !printf("U");
    printf("S\n");
    for(auto a:ans)printf("%d %d %d\n",a[0],a[1],a[2]);
}