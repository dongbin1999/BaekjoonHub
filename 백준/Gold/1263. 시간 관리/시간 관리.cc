#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    int n;scanf("%d",&n);
    vector<pii> v(n);
    for(auto &[x,y]:v)scanf("%d%d",&y,&x);
    sort(v.begin(),v.end(),greater<pii>());
    int ans=2e9;
    for(auto [x,y]:v){
        ans=min(ans,x);
        if(ans-y<0)return !printf("-1");
        ans-=y;
    }
    printf("%d",ans);
    return 0;
}