#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=1;i<n-1;i++)ans=max({ans,abs(v[0]+v[i+1]-2*v[i]),abs(v[i-1]+v.back()-2*v[i]),
                                   abs(v[0]+v.back()-2*v[i]),abs(v[i-1]+v[i+1]-2*v[i])});
    printf("%d",ans);
    return 0;
}