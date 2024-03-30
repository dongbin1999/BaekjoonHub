#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int sz=1<<17;
int arr[sz*2];

int query(int s,int e,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)/2;
    return query(s,e,node*2,ns,mid)+query(s,e,node*2+1,mid+1,ne);
}

void update(int i,int x=1){
    i+=sz;arr[i]+=x;
    while(i>1)i/=2,arr[i]=arr[i*2]+arr[i*2+1];
}

int main(){
    int n;scanf("%d",&n);
    vector<pii> v(n);
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        v[i]={x,i};
    }
    sort(v.begin(),v.end(),greater<pii>());
    bool b=0;
    for(auto [x,y]:v){
        update(y);
        b^=query(0,y-1)&1;
    }
    memset(arr,0,sizeof(arr));
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        v[i]={x,i};
    }
    sort(v.begin(),v.end(),greater<pii>());
    bool bb=0;
    for(auto [x,y]:v){
        update(y);
        bb^=query(0,y-1)&1;
    }
    printf(b^bb?"Impossible":"Possible");
}