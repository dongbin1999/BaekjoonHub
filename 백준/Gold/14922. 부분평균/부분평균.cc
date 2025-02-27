#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    vector<ll> v(n);
    for(int i=0;i<n;i++)scanf("%lld",&v[i]);
    pair<ll,int> ans={2e18,-1};
    for(int i=0;i<n-1;i++){
        ans=min(ans,{(v[i]+v[i+1])*3,i});
        if(i<n-2)ans=min(ans,{(v[i]+v[i+1]+v[i+2])*2,i});
    }
    printf("%d",ans.second);
}