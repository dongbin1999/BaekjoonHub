#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

void solve(){
    int n,k;scanf("%d%d",&n,&k);
    vector<pii> v(n);
    for(auto &[x,y]:v)scanf("%d%d",&x,&y);
    sort(v.begin(),v.end());
    vector<int> p;
    for(auto [x,y]:v)p.push_back(y);
    int l=0,r=3e8,mid,ans=r;
    while(l<=r){
        mid=l+r>>1;
        int cnt=0,mn=p[0],mx=p[0];
        for(int i=1;i<n;i++){
            mn=min(mn,p[i]),mx=max(mx,p[i]);
            if(mx-mn>mid)mn=mx=p[i],cnt++;
        }
        if(cnt<k)ans=min(ans,mid),r=mid-1;
        else l=mid+1;
    }
    printf("%d.%d\n",ans/2,ans%2*5);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
}