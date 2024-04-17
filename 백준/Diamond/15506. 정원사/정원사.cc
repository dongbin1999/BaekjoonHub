#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1<<17;

int ans[sz<<1],weednum,idx[1000000];
ll H[1000000];
bitset<1000000> exist;

struct cmp{
    bool operator()(int a,int b){
        return H[a]<H[b];
    }
};
priority_queue<int,vector<int>,cmp> arr[sz<<1];

void add(int i,int num){
    i+=sz,arr[i].push(num),ans[i]++;
    while(i>1)i>>=1,arr[i].push(num),ans[i]=ans[i<<1]+ans[i<<1|1];
}
void del(int i){
    i+=sz,ans[i]--;
    while(i>1)i>>=1,ans[i]=ans[i<<1]+ans[i<<1|1];
}
int query(int s,int e,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return ans[node];
    int mid=(ns+ne)>>1;
    return query(s,e,node<<1,ns,mid)+query(s,e,node<<1|1,mid+1,ne);
}

void del(int s,int e,ll h,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return;
    if(s<=ns&&ne<=e){
        while(!arr[node].empty()){
            int num=arr[node].top();
            if(H[num]<=h)break;
            if(exist[num])del(idx[num]),exist[num]=0;
            arr[node].pop();
        }
        return;
    }
    int mid=(ns+ne)>>1;
    del(s,e,h,node<<1,ns,mid),del(s,e,h,node<<1|1,mid+1,ne);
}

int main(){
    int n,m;ll k;scanf("%d%d%lld",&n,&m,&k);
    while(m--){
        int op;scanf("%d",&op);
        if(op==1){
            ll t,h;int x;scanf("%lld%d%lld",&t,&x,&h);
            exist[weednum]=1,idx[weednum]=x,H[weednum]=h-t*k;
            add(x,weednum++);
        }
        if(op==2){
            ll t,h;int l,r;scanf("%lld%d%d%lld",&t,&l,&r,&h);
            del(l,r,h-t*k);
        }
        if(op==3){
            ll t;int l,r;scanf("%lld%d%d",&t,&l,&r);
            printf("%d\n",query(l,r));
        }
    }
}