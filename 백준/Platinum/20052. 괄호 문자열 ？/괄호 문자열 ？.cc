#include<bits/stdc++.h>
using namespace std;
const int sz=1<<17;
int arr[2][sz*2];
char st[sz];

int query(int s,int e,bool b,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return 1e9;
    if(s<=ns&&ne<=e)return arr[b][node];
    int mid=(ns+ne)/2;
    return min(query(s,e,b,node*2,ns,mid),query(s,e,b,node*2+1,mid+1,ne));
}

void update(int i,bool b,int x){
    i+=sz;arr[b][i]=x;
    while(i>1)i/=2,arr[b][i]=min(arr[b][i*2],arr[b][i*2+1]);
}

int main(){
    scanf("%s",st+1);
    int m;scanf("%d",&m);
    int ans=0,x=0,n=strlen(st+1);
    for(int i=1;i<=n;i++){
        x+=st[i]=='('?1:-1;
        update(i,0,x);
    }
    x=0;
    for(int i=n;i>=1;i--){
        x+=st[i]==')'?1:-1;
        update(i,1,x);
    }
    while(m--){
        int s,e;scanf("%d%d",&s,&e);
        int l=query(s,e,0);
        if(s>1)l-=query(s-1,s-1,0);
        int r=query(s,e,1);
        if(e<n)r-=query(e+1,e+1,1);
        ans+=l>=0&&r>=0;
    }
    printf("%d",ans);
}