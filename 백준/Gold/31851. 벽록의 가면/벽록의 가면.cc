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

bool intersect(pii a,pii b,pii c,pii d){
    ll check[4]={ccw(a,b,c),ccw(a,b,d),ccw(c,d,a),ccw(c,d,b)};
    for(int i=0;i<4;i++)
        check[i]=check[i]<0?-1:check[i]!=0;
    ll ab=check[0]*check[1], cd=check[2]*check[3];
    if(!ab&&!cd)
    {
        if(a>b) swap(a,b);
        if(c>d) swap(c,d);
        return a<=d&&c<=b;
    }
    return ab<=0&&cd<=0;
}

bool inside(vector<pii> &ch,pii p){
    int n=ch.size();
    if(ccw(ch[0],ch[n-1],p)>0||ccw(ch[0],ch[1],p)<0) return false;
    int l=1,r=n-1,mid,lseg=0;
    while(l<=r){
        mid=(l+r)/2;
        if(ccw(ch[0],ch[mid],p)>0)lseg=max(lseg,mid),l=mid+1;
        else r=mid-1;
    }
    return ccw(ch[lseg],ch[lseg+1],p)>0;
}

int main(){
    int n;scanf("%d",&n);
    vector<pii> v(n);
    for(auto &[x,y]:v)scanf("%d%d",&x,&y);
    int ans=n*(n-1)*(n-2)*(n-3)/24;
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int k=j+1;k<n;k++)for(int l=0;l<n;l++){
        if(l==i||l==j||l==k)continue;
        vector<pii> V={v[i],v[j],v[k]};
        auto ch=convex_hull(V);
        ans-=inside(ch,v[l]);
    }
    printf("%d",ans);
}