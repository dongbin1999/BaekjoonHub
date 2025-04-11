#include<bits/stdc++.h>
using namespace std;
const int r=19,sz=1<<r;
vector<int> tree[sz];
int dep[sz],sparse[sz][r],in[sz],out[sz],dfsn,sub[sz];
int arr[sz<<1];

void update(int i,int val){
    i+=sz,arr[i]+=val;
    while(i>1)i>>=1,arr[i]=arr[i<<1]+arr[i<<1|1];
}

int query(int s,int e,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)>>1;
    return query(s,e,node<<1,ns,mid)+query(s,e,node<<1|1,mid+1,ne);
}

int go(int cur=1,int d=0,int par=-1){
    sub[cur]=1,in[cur]=++dfsn,dep[cur]=d;
    sparse[cur][0]=par;
    for(int i=1;i<r;i++)sparse[cur][i]=sparse[sparse[cur][i-1]][i-1];
    for(int nx:tree[cur])
        if(par!=nx)sub[cur]+=go(nx,d+1,cur);
    out[cur]=dfsn;
    return sub[cur];
}

int get_node(int from,int to){
    if(in[to]>in[from]||out[from]>out[to])return sparse[to][0];
    int diff=dep[from]-dep[to];
    for(int i=r-1;i>=0;i--)
        if(diff>(1<<i))diff-=(1<<i),from=sparse[from][i];
    return from;
}

int main(){
    int n;scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int p;scanf("%d",&p);
        tree[p].push_back(i),tree[i].push_back(p);
    }
    go();
    int cen=1;
    printf("1 "),update(in[1],1);
    for(int i=2;i<=n;i++){
        update(in[i],1);
        int node=get_node(i,cen);
        vector<int> able;
        //printf("cen%d : %d %d-> %d / %d\n",cen,in[cen],out[cen],query(in[cen],out[cen]),query(in[cen],in[cen]));
        //printf("node%d : %d %d-> %d / %d\n",node,in[node],out[node],query(in[node],out[node]),query(in[node],in[node]));
        if(sparse[cen][0]==node){
            int cnt=query(in[cen],out[cen]);
            if(cnt*2<=i)able.push_back(node);
            else able.push_back(cen);
        }
        else{
            int cnt=query(in[node],out[node]);
            //printf("[%d : %d,%d->%d]\n",i,node,cen,cnt);
            if(cnt*2<=i)able.push_back(cen);
            if((i-cnt)*2<=i)able.push_back(node);
        }
        sort(able.begin(),able.end());
        cen=able[0];
        printf("%d ",cen);
    }
}