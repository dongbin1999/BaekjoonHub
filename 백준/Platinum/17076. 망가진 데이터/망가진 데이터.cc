#include<bits/stdc++.h>
using namespace std;
const int sz=1<<18;
vector<int> arr[sz*2];
int mx[sz*2];
void construct(){
    for(int i=sz-1;i>=1;i--){
        int li=0,ri=0,left=i*2,right=i*2+1;
        while(li<arr[left].size()&&ri<arr[right].size())
            arr[i].push_back(arr[left][li]<arr[right][ri]?arr[left][li++]:arr[right][ri++]);
        while(li<arr[left].size())arr[i].push_back(arr[left][li++]);
        while (ri<arr[right].size())arr[i].push_back(arr[right][ri++]);
    }
}

int Q(int s,int e,int v,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e){
        int l=0,r=arr[node].size()-1,mid,ret=0;
        if(arr[node][l]>v)return 0;
        while(l<=r){
            mid=(l+r)/2;
            if(arr[node][mid]<=v)ret=max(ret,mid),l=mid+1;
            else r=mid-1;
        }
        return ret+1;
    }
    int mid=(ns+ne)/2;
    return Q(s,e,v,node*2,ns,mid)+Q(s,e,v,node*2+1,mid+1,ne);
}

int query(int s,int e,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return mx[node];
    int mid=(ns+ne)/2;
    return max(query(s,e,node*2,ns,mid),query(s,e,node*2+1,mid+1,ne));
}

void update(int i,int x){
    i+=sz;mx[i]=x;
    while(i>1)i/=2,mx[i]=max(mx[i*2],mx[i*2+1]);
}

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
        arr[i+sz].push_back(v[i]);
        update(i,v[i]);
    }
    construct();
    pair<int,int> ans={-1,-1};
    for(int i=2;i<n;i++){
        int N=query(1,i-1);
        if(Q(i+1,n,N)/2>=v[i])ans=max(ans,{N,v[i]});
    }
    if(ans.first==-1)return !printf("-1");
    printf("%d %d",ans.first,ans.second);
}