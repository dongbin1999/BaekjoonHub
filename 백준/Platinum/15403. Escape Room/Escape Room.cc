#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n;scanf("%d",&n);
    vector<int> v(n),ans(n);
    vector<pii> vv;
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        vv.push_back({v[i],i});
    }
    sort(vv.begin(),vv.end(),greater<pii>());
    int x=1;
    for(auto [n,idx]:vv)
        ans[idx]=x++;
    for(auto i:ans)printf("%d ",i);
    return 0;
}