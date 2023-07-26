#include<bits/stdc++.h>
using namespace std;
const int sz=1<<18;
vector<int> graph[sz];
int junyoung,sungmin,numbering;

vector<int> line;map<int,int> road;
void findLine(int cur,int pre,vector<int> &v){
    v.push_back(cur);
    if(cur==sungmin){
        line=v;
        for(auto i:line)if(!road[i])road[i]=++numbering;
        return;
    }
    for(auto nx:graph[cur])
        if(nx!=pre)findLine(nx,cur,v);
    v.pop_back();
}

int arr[2][sz*2];
void update(int i,int v,bool b){
    i+=sz,arr[b][i]=v;
    while(i>1)i/=2,arr[b][i]=max(arr[b][i*2],arr[b][i*2+1]);
}

int query(int s,int e,int node,int ns,int ne,bool b){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return arr[b][node];
    int mid=(ns+ne)/2;
    return max(query(s,e,node*2,ns,mid,b),query(s,e,node*2+1,mid+1,ne,b));
}int query(int s,int e,bool b){return query(s,e,1,0,sz-1,b);}

void dfs(int cur,int pre,int node,int dist,bool b){
    if(query(road[node],road[node],b)<dist)update(road[node],dist,b);
    for(auto nx:graph[cur]){
        if(nx==pre)continue;
        if(road.find(nx)!=road.end())
            dfs(nx,cur,nx,dist+1,b);
        else dfs(nx,cur,node,dist+1,b);
    }
}

int ans(int turn){
    int l=road[line[(turn+1)/2]],r=road[line[line.size()-1-turn/2]];
    //printf("<%d> [%d %d]",turn,l,r);
    if(l>=r)return 1e9;
    int x;
    if(turn%2)x=query(r,r,1)-query(l,r-1,0);
    else x=query(l,l,0)-query(l+1,r,1);
    //printf("%d %d %d : %d\n",turn,x,turn+1,ans(turn+1));
    return max(x,-ans(turn+1));
}

int main(){
    int n;scanf("%d%d%d",&n,&junyoung,&sungmin);
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> v;
    findLine(junyoung,-1,v);
    dfs(junyoung,-1,junyoung,0,0);
    dfs(sungmin,-1,sungmin,0,1);
    printf("%d",ans(0));
    return 0;
}