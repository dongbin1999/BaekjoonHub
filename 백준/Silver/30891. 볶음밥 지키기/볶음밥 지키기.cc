#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tup;
 
int main(){
    int n,r;scanf("%d%d",&n,&r);
    vector<pii> v(n);
    for(auto &[rx,ry]:v)scanf("%d%d",&rx,&ry);
    tup ans={0,0,0};
    for(int x=-100;x<=100;x++)for(int y=-100;y<=100;y++){
        int save=0;
        for(auto &[rx,ry]:v)
            if(r*r>=(x-rx)*(x-rx)+(y-ry)*(y-ry))
                save++;
        ans=max(ans,{save,x,y});
    }
    auto [s,x,y]=ans;
    printf("%d %d",x,y);
    return 0;
}