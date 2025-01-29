#include<bits/stdc++.h>
using namespace std;
char s[500005];
vector<int> tree[500001];
int d[500001],sd[500001],md;
int go(int node=1,int pa=-1,int dep=1){
    d[node]=sd[node]=dep,md=max(md,dep);
    for(auto nx:tree[node])
        if(nx!=pa)sd[node]=max(go(nx,node,dep+1),sd[nx]);
    return sd[node];
}

int main(){
    int n;scanf("%d %s",&n,s+1);
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        tree[x].push_back(y),tree[y].push_back(x);
    }
    go();
    vector<char> ans;
    queue<int> q,q2;
    q.push(1);
    while(1){
        ans.push_back(s[q.front()]);
        char mx=-1;
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(auto nx:tree[cur]){
                if(d[cur]>d[nx])continue;
                if(mx<s[nx]){
                    while(!q2.empty())q2.pop();
                    q2.push(nx),mx=s[nx];
                }
                else if(mx==s[nx])q2.push(nx);
            }
        }
        if(mx==-1)break;
        q=q2;
    }
    for(auto i:ans)printf("%c",i);
}