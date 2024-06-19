#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll ccw(pii a,pii b,pii c){
    ll x[3]={a.first,b.first,c.first},y[3]={a.second,b.second,c.second};
    return x[0]*y[1]+x[1]*y[2]+x[2]*y[0]-(y[0]*x[1]+y[1]*x[2]+y[2]*x[0]);
}
ll dist(pii a,pii b){
    return (ll)(a.first-b.first)*(a.first-b.first)+(ll)(a.second-b.second)*(a.second-b.second);
}
vector<pii> convex_hull(vector<pii> &v){
    vector<pii> ret;
    swap(v[0],*min_element(v.begin(),v.end()));
    sort(v.begin()+1,v.end(),[&](pii a,pii b){
        ll cw=ccw(v[0],a,b);
        if(cw)return cw>0;
        return dist(v[0],a)<dist(v[0],b);
    });
    for(auto i:v){
        while(ret.size()>=2&&ccw(ret[ret.size()-2],ret.back(),i)<=0)ret.pop_back();
        ret.push_back(i);
    }
    return ret;
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<pii> a(n),b(m),v;
    for(auto &[x,y]:a)scanf("%d%d",&x,&y);
    for(auto &[x,y]:b)scanf("%d%d",&x,&y);
    for(auto [ax,ay]:a)for(auto[bx,by]:b)v.push_back({ax+bx,ay+by});
    auto ch=convex_hull(v);
    printf("%d\n",ch.size());
    for(auto [x,y]:ch)printf("%d %d\n",x,y);
    return 0;
}