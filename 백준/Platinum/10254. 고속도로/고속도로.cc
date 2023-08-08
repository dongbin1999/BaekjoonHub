#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> plii;

pii operator-(pii a,pii b){return {a.first-b.first,a.second-b.second};}

ll ccw(pii a,pii b,pii c){
    ll x[3]={a.first,b.first,c.first},y[3]={a.second,b.second,c.second};
    return x[0]*y[1]+x[1]*y[2]+x[2]*y[0]-(y[0]*x[1]+y[1]*x[2]+y[2]*x[0]);
}
ll ccw(pii a,pii b){
    return (ll)a.first*(ll)b.second-(ll)b.first*(ll)a.second;
}
ll dist(pii a,pii b){
    return (ll)(a.first-b.first)*(a.first-b.first)+(ll)(a.second-b.second)*(a.second-b.second);
}
vector<pii> convex_hull(vector<pii> v){
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

void solve(){
    int n;scanf("%d",&n);
    vector<pii> v(n);
    for(int i=0;i<n;i++)scanf("%d%d",&v[i].first,&v[i].second);

    vector<pii> ch=convex_hull(v);
    n=ch.size();
    plii ans={0,{0,0}};
    int a=min_element(ch.begin(),ch.end())-ch.begin(),b=max_element(ch.begin(),ch.end())-ch.begin();
    for(int i=0;i<n;i++){
        ans=max(ans,{dist(ch[a],ch[b]),{a,b}});
        pii v1=ch[a]-ch[(a+1)%n],v2=ch[b]-ch[(b+1)%n];
        ccw(v1,v2)>0?b=(b+1)%n:a=(a+1)%n;
    }
    printf("%d %d %d %d\n",ch[ans.second.first].first,ch[ans.second.first].second,
           ch[ans.second.second].first,ch[ans.second.second].second);
}

int main(){
    int tc;scanf("%d",&tc);
    while(tc--)solve();
    return 0;
}
