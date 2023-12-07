#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n;scanf("%d",&n);
    vector<pii> v(n);
    for(auto &[x,y]:v)scanf("%d%d",&x,&y);
    double ans=0.0;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        auto [ax,ay]=v[i];auto [bx,by]=v[j];
        ans+=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))/n;
    }
    printf("%lf",ans);
    return 0;
}