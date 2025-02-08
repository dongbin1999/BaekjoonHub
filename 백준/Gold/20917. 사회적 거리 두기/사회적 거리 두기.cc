#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,s;scanf("%d%d",&n,&s);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    int l=0,r=1e9,mid,ans=l;
    while(l<=r){
        mid=l+r>>1;
        int cnt=1,a=v[0];
        for(int i=1;i<n;i++)
            if(v[i]-a>=mid)a=v[i],cnt++;
        if(cnt>=s)ans=max(ans,mid),l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",ans);
}
int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}