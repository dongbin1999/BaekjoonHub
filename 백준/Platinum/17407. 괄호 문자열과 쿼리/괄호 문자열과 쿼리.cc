#include<bits/stdc++.h>
using namespace std;
const int sz=1<<17;
int arr[2][sz*2],lazy[2][sz*2];
char st[sz];

void propagate(bool b,int node){
    if(!lazy[b][node])return;
    if(node<sz){
        lazy[b][node<<1]+=lazy[b][node];
        lazy[b][node<<1|1]+=lazy[b][node];
    }
    arr[b][node]+=lazy[b][node];
    lazy[b][node]=0;
}

void update(int s,int e,int k,bool b,int node=1,int ns=0,int ne=sz-1){
    propagate(b,node);
    if(e<ns||ne<s)return;
    if (s<=ns&&ne<=e){
        lazy[b][node]+=k;
        propagate(b,node);return;
    }
    int mid=(ns+ne)>>1;
    update(s,e,k,b,node<<1,ns,mid),update(s,e,k,b,node<<1|1,mid+1,ne);
    arr[b][node]=min(arr[b][node<<1],arr[b][node<<1|1]);
}

int query(int s,int e,bool b,int node=1,int ns=0,int ne=sz-1){
    propagate(b,node);
    if(e<ns||ne<s)return 1e9;
    if(s<=ns&&ne<=e)return arr[b][node];
    int mid=(ns+ne)/2;
    return min(query(s,e,b,node*2,ns,mid),query(s,e,b,node*2+1,mid+1,ne));
}

int main(){
    scanf("%s",st+1);
    int m;scanf("%d",&m);
    int ans=0,n=strlen(st+1);
    for(int i=1,x=0;i<=n;i++){
        x+=st[i]=='('?1:-1;
        update(i,i,x,0);
    }
    for(int i=n,x=0;i>=1;i--){
        x+=st[i]==')'?1:-1;
        update(i,i,x,1);
    }
    while(m--){
        int x;scanf("%d",&x);
        update(x,n,st[x]=='('?-2:2,0),update(1,x,st[x]==')'?-2:2,1);
        ans+=query(1,n,0)>=0&&query(1,n,1)>=0;
        st[x]=st[x]=='('?')':'(';
    }
    printf("%d",ans);
}