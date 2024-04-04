#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1<<17;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    ll n;cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    map<string,ll> ma;
    sort(s.begin(),s.end());
    for(int i=0;i<n;i++){
        string ss=s[i];
        reverse(ss.begin(),ss.end());
        ma[ss]=i+1;
    }
    ll ans=n*(n-1)/2;
    for(auto [a,b]:ma){
        ans-=query(0,b);
        update(b,1);
    }
    cout<<ans;
}