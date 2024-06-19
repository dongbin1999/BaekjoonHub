#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
#define ix(x) (lower_bound(cx.begin(),cx.end(),x)-cx.begin())
#define iy(y) (lower_bound(cy.begin(),cy.end(),y)-cy.begin())
const int sz=1<<12;
ll arr[sz<<1];

void update(int i,ll val){
    i+=sz,arr[i]=val;
    while(i>1)i>>=1,arr[i]=arr[i<<1]+arr[i<<1|1];
}
ll query(int s,int e,int node=1,int ns=0,int ne=sz-1){
    if(e<ns||ne<s)return 0;
    if(s<=ns&&ne<=e)return arr[node];
    int mid=(ns+ne)>>1;
    return query(s,e,node<<1,ns,mid)+query(s,e,node<<1|1,mid+1,ne);
}

int main(){
    int n;scanf("%d",&n);
    vector<pii> v(n);
    vector<int> cx,cy;
    for(auto &[x,y]:v){
        scanf("%d%d",&x,&y);
        cx.push_back(x),cy.push_back(y);
    }
    UNIQUE(cx);UNIQUE(cy);
    sort(v.begin(),v.end());
    ll ans=n+1;
    for(int i=0;i<n;i++){
        memset(arr,0,sizeof(arr));
        int a=iy(v[i].second);
        update(a,1);
        for(int j=i+1;j<n;j++){
            int b=iy(v[j].second);
            update(b,1);
            ans+=query(0,min(a,b))*query(max(a,b),n);
        }
    }
    printf("%lld",ans);
    return 0;
}