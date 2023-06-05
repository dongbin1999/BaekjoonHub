#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<int> s(n+m),t(n+m),a,b;
    for(int i=0;i<n+m;i++){
        scanf("%1d",&s[i]);
        if(s[i])a.push_back(i);
    }
    for(int i=0;i<n+m;i++){
        scanf("%1d",&t[i]);
        if(t[i])b.push_back(i);
    }
    ll ans=0;
    for(int i=0;i<a.size();i++)
        ans+=abs(a[i]-b[i]);
    ll x=ans/2,y=(ans+1)/2;
    printf("%lld",x*x+y*y);
    return 0;
}