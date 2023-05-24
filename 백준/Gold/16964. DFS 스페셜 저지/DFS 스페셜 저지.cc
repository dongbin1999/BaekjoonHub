#include <bits/stdc++.h>
using namespace std;

vector<int> tree[100002];
int in[100002],p[100002];
stack<int> s;
void dfs(int node, int pa){
    p[node]=pa;
    for(auto go:tree[node])
        if(go!=pa)dfs(go,node);
}
int main(){
    int n;scanf("%d",&n);
    s.push(1);in[1]=1e9;
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        tree[x].push_back(y);
        tree[y].push_back(x);
        in[x]++,in[y]++;
    }
    dfs(1,1);
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        if(!i&&x!=1) return !printf("0");
        if(s.top()!=p[x]) return !printf("0");
        s.push(x);
        while(in[x]==1)in[x]--,in[p[x]]--,x=p[x],s.pop();
    }
    printf("1");
    return 0;
}