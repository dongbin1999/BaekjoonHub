#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> a;
int ans=2e9;
void f(int k,vector<pii> &v){
    if(!k){
        int ret=0;
        for(int i=0;i<v.size();i++){
            int tmp=1e9;
            for(auto [x,y]:a)tmp=min(tmp,abs(x-v[i].first)+abs(y-v[i].second));
            ret=max(ret,tmp);
        }
        ans=min(ans,ret);
        return;
    }
    for(int i=0;i<v.size();i++){
        a.push_back(v[i]);
        f(k-1,v);
        a.pop_back();
    }
}

int main(){
    int n,k;scanf("%d%d",&n,&k);
    vector<pii> v(n);
    for(auto &[x,y]:v)scanf("%d%d",&x,&y);
    f(k,v);
    printf("%d",ans);
    return 0;
}