#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

ll ccw(pii a,pii b,pii c){
    ll x[3]={a.first,b.first,c.first},y[3]={a.second,b.second,c.second};
    return x[0]*y[1]+x[1]*y[2]+x[2]*y[0]-(y[0]*x[1]+y[1]*x[2]+y[2]*x[0]);
}
ll dist(pii a,pii b){
    return (ll)(a.first-b.first)*(a.first-b.first)+(ll)(a.second-b.second)*(a.second-b.second);
}

map<pii,pii> removed;
vector<pii> convex_hull(vector<pii> v){
    vector<pii> ret;
    swap(v[0],*min_element(v.begin(),v.end()));
    sort(v.begin()+1,v.end(),[&](pii a,pii b){
        ll cw=ccw(v[0],a,b);
        if(cw)return cw>0;
        return dist(v[0],a)<dist(v[0],b);
    });
    for(auto i:v){
        if(ret.size()>=2&&ccw(ret[ret.size()-2],ret.back(),i)<=0)
            removed[i]=ret.back(),ret.pop_back();
        ret.push_back(i);
    }
    return ret;
}
vector<pii> ans,tmp;
void go(pii p){
    if(removed.count(p))go(removed[p]);
    tmp.push_back(p);
}

int main(){
    int n;scanf("%d",&n);
    vector<pii> v;
    while(n--){
        int x,y;char c;scanf("%d%d %c",&x,&y,&c);
        if(c=='Y')v.push_back({x,y});
    }
    v=convex_hull(v);
    for(int i=0;i<v.size();i++){
        pii p=v[i],pre=v[(i+v.size()-1)%v.size()];
        go(p);
        if(pre<tmp[0]!=p<tmp[0])reverse(tmp.begin(),tmp.end());
        while(!tmp.empty())ans.push_back(tmp.back()),tmp.pop_back();
    }
    printf("%d\n",ans.size());
    for(auto [x,y]:ans)printf("%d %d\n",x,y);
}