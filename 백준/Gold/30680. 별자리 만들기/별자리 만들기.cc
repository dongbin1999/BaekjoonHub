#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;
vector<int> d;
vector<int> tree[100001];
void go(int node=1,int pa=-1,int depth=1){
    if(tree[node].size()==1&&node!=1)d.push_back(depth);
    for(auto nx:tree[node])if(nx!=pa)go(nx,node,depth+1);
}

int main(){
    int n;scanf("%d",&n);
    int ans=0;
    pq.push(0);
    while(n--){
        int a;scanf("%d",&a);
        for(int i=1;i<a;i++){
            int v,w;scanf("%d%d",&v,&w);
            tree[v].push_back(w),tree[w].push_back(v);
        }
        go();
        int x=pq.top();pq.pop();
        while(!d.empty())pq.push(x+d.back()),d.pop_back();
        for(int i=1;i<=a;i++)tree[i].clear();
    }
    while(!pq.empty())ans=max(ans,pq.top()),pq.pop();
    printf("%d",ans);
}