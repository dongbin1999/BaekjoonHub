#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
const int sz=1<<18;
int arr[sz<<1];
void update(int i){
    i+=sz,arr[i]++;
    while(i>1)i>>=1,arr[i]=arr[i<<1]+arr[i<<1|1];
}

int query(int s,int e,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)>>1;
    return query(s,e,node<<1,ns,mid)+query(s,e,node<<1|1,mid+1,ne);
}

int main(){
    int n;scanf("%d",&n);
    vector<int> a(n);
    ans.resize(n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    int x=a.back()%(n-1),m=0,ok=0;
    swap(a[0],a[x]);
    ans[ok++]=a[0],update(0);
    while(ok<n){
        m=(a[ok-1]+m-1)%(n-ok);
        int l=0,r=n-1,mid,idx=n-1;
        while(l<=r){
            mid=(l+r)/2;
            int z=mid-query(0,mid);
            if(z>=m)idx=min(idx,mid),r=mid-1;
            else l=mid+1;
        }
        ans[idx]=a[ok++],update(idx);
    }
    for(auto i:ans)printf("%d\n",i);
}