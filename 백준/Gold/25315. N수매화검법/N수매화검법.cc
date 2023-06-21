#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define X first
#define Y second

struct segment{pll A,B;ll x;};
ll ccw(pll A,pll B,pll C){
    return A.X*B.Y+B.X*C.Y+C.X*A.Y-(A.Y*B.X+B.Y*C.X+C.Y*A.X);}

bool intersect(segment s1,segment s2)//선분 ab, 선분 cd.
{
    pll a=s1.A,b=s1.B,c=s2.A,d=s2.B;
    //선분ab,점c / 선분ab,점d / 선분cd,점a / 선분cd,점b
    ll check[4]={ccw(a,b,c),ccw(a,b,d),ccw(c,d,a),ccw(c,d,b)};
    for(int i=0;i<4;i++)
        check[i]=check[i]<0?-1:check[i]!=0;//오버플로우 처리.
    ll ab=check[0]*check[1], cd=check[2]*check[3];
    if(!ab&&!cd)//세 점이 일직선상.
    {
        if(a>b) swap(a,b);
        if(c>d) swap(c,d);
        return a<=d&&c<=b;//(a-c-b-d) or (c-a-d-b)
    }
    return ab<=0&&cd<=0;
}

int main(){
    int n;scanf("%d",&n);
    ll ans=0;
    vector<segment> v;
    for(int i=0;i<n;i++){
        int a,b,c,d;ll e;scanf("%d%d%d%d%lld",&a,&b,&c,&d,&e);
        segment t;t.A={a,b},t.B={c,d},t.x=e;
        v.push_back(t);
        ans+=e;
    }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
        if(intersect(v[i],v[j]))ans+=min(v[i].x,v[j].x);
    }
    printf("%lld",ans);
    return 0;
}