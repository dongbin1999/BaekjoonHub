#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> act(1),draw(1),pt(1);

/* 1. 행동횟수-1 -> 드로우횟수 +d
 * draw[i] : 1번을 i번 했을 때 얻는 드로우횟수 최댓값
 * 2. 드로우횟수-1 -> 포인트획득 +p
 * pt[i] : point카드를 i개 뽑았을 때 얻는 점수 최댓값
 * 3. 드로우횟수-1 -> 행동횟수 +a
 * act[i] : 3번을 i번 했을 때 얻는 행동횟수 최댓값
 * */

ll get_score(ll a,ll d){
    if(!a||!d||a+d<=2){//1,3번 연쇄작용 불가능.
        if(a==1&&d==1&&draw.size()>1)d+=draw[1];
        return pt[min((ll)pt.size()-1,d)];
    }
    ll maximum=draw[min((ll)draw.size()-1,a+act.back())];
    ll l=0,r=act.size()-1,mid,mn=r;//3번을 mn번만 해도, draw횟수를 최대로 늘리는 게 가능하다.
    while(l<=r){
        mid=(l+r)/2;
        ll aa=a+act[mid];
        if(draw[min((ll)draw.size()-1,aa)]==maximum)
            mn=min(mn,mid),r=mid-1;
        else l=mid+1;
    }
    d+=maximum-mn;
    return pt[min((ll)pt.size()-1,d)];
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    ll a=1,d=1;
    while(n--){
        char s[10];scanf(" %s",s);
        if(s[0]=='A'){
            ll x,y;scanf("%lld%lld",&x,&y);
            x--,y--;
            if(x>=0&&y>=0)a+=x,d+=y;
            else if(x<0&&y>0)draw.push_back(y);
            else if(x>0&&y<0)act.push_back(x);
        }
        else{
            ll x;scanf("%lld",&x);
            pt.push_back(x);
        }
    }

    sort(act.begin()+1,act.end(),greater<ll>());
    sort(draw.begin()+1,draw.end(),greater<ll>());
    sort(pt.begin()+1,pt.end(),greater<ll>());
    for(int i=1;i<act.size();i++)act[i]+=act[i-1];
    for(int i=1;i<draw.size();i++)draw[i]+=draw[i-1];
    for(int i=1;i<pt.size();i++)pt[i]+=pt[i-1];

    ll ans=get_score(a,d);
    while(m--){
        char s[10];scanf(" %s",s);
        if(s[0]=='A'){
            ll x,y;scanf("%lld%lld",&x,&y);
            ans=max(ans,get_score(a-1+x,d-1+y));
        }
        else{
            ll x;scanf("%lld",&x);
            ans=max(ans,x+get_score(a,d-1));
        }
    }
    printf("%lld",ans);
    return 0;
}