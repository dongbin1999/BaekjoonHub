#include<bits/stdc++.h>
using namespace std;
const int sz=1<<20;
typedef array<int,3> tup;
typedef pair<int,int> pii;
int arr[sz<<1];
int xsum[sz],ysum[sz];
vector<pii> doty[sz],dotx[sz];

void update(int i,int val){
    i+=sz,arr[i]+=val;
    while(i>1)i>>=1,arr[i]=max(arr[i<<1],arr[i<<1|1]);
}
int query(int s,int e,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)>>1;
    return max(query(s,e,node<<1,ns,mid),query(s,e,node<<1|1,mid+1,ne));
}

int pos;
void get_pos(int node=1,int ns=0,int ne=sz-1){
    if(ns==ne){pos=node-sz;return;}
    int mid=(ns+ne)>>1;
    if(arr[node<<1]==arr[1])get_pos(node<<1,ns,mid);
    else get_pos(node<<1|1,mid+1,ne);
}

int main(){
    int n;scanf("%d",&n);
    vector<tup> a(n);
    for(auto &[x,y,v]:a){
        scanf("%d%d%d",&x,&y,&v);
        xsum[x]+=v,ysum[y]+=v;
        doty[y].push_back({x,v});
        dotx[x].push_back({y,v});
    }
    int ans=0;
    //1. y축에 1번의 검격(x값 고정), x축에 2번의 검격
    for(auto [x,y,v]:a)update(y,v);
    for(int x=0;x<sz;x++){
        int tmp=xsum[x];
        for(auto [y,v]:dotx[x])update(y,-v);
        vector<int> rollback;
        tmp+=arr[1],get_pos(),rollback.push_back(pos);
        update(rollback.back(),-2e9);
        tmp+=arr[1],get_pos(),rollback.push_back(pos);
        update(rollback.back(),-2e9);
        for(auto idx:rollback)update(idx,2e9);
        for(auto [y,v]:dotx[x])update(y,v);
        ans=max(ans,tmp);
    }
    //2. x축에 1번의 검격(y값 고정), y축에 2번의 검격
    memset(arr,0,sizeof(arr));
    for(auto [x,y,v]:a)update(x,v);
    for(int y=0;y<sz;y++){
        int tmp=ysum[y];
        for(auto [x,v]:doty[y])update(x,-v);
        vector<int> rollback;
        tmp+=arr[1],get_pos(),rollback.push_back(pos);
        update(rollback.back(),-2e9);
        tmp+=arr[1],get_pos(),rollback.push_back(pos);
        update(rollback.back(),-2e9);
        for(auto idx:rollback)update(idx,2e9);
        for(auto [x,v]:doty[y])update(x,v);
        ans=max(ans,tmp);
    }
    //3. x축에 3번의 검격
    sort(ysum,ysum+sz);
    ans=max(ans,ysum[sz-1]+ysum[sz-2]+ysum[sz-3]);
    //4. y축에 3번의 검격
    sort(xsum,xsum+sz);
    ans=max(ans,xsum[sz-1]+xsum[sz-2]+xsum[sz-3]);
    printf("%d",ans);
}