#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<int> pl,mi;
    while(n--){
        int x;scanf("%d",&x);
        if(x>0)pl.push_back(x);
        else mi.push_back(-x);
    }
    sort(pl.begin(),pl.end());
    sort(mi.begin(),mi.end());
    int ans=0;
    for(int i=pl.size()-1;i>=0;i-=m)ans+=pl[i];
    for(int i=mi.size()-1;i>=0;i-=m)ans+=mi[i];
    ans*=2;
    ans-=max((pl.empty()?0:pl.back()),(mi.empty()?0:mi.back()));
    printf("%d",ans);
}