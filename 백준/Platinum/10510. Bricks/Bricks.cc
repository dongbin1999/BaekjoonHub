#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;

int s(ll x,ll y,ll cx,ll cy){
    if(x*cy<cx*y)return -1;
    else if(x*cy==cx*y)return 0;
    else return 1;
}
void solve(){
    int n,ans=0;scanf("%d",&n);
    vector<pair<long long,char>> v(n);
    ll x=0,y=0,cx=0,cy=0;
    for(auto &[k,c]:v){
        scanf(" %lld %c",&k,&c);
        if(c=='B')x+=k;else y+=k;
    }
    if(!x||!y){printf("%lld\n",(ll)max(x,y));return;}
    for(auto [k,c]:v){
        int pre=s(x,y,cx,cy);
        if(c=='B')cx+=k;else cy+=k;
        int cur=s(x,y,cx,cy);
        if(cur&&pre*cur!=-1)continue;
        if(c=='B'&&(cy*x)%y==0)ans++;
        if(c=='W'&&(cx*y)%x==0)ans++;
    }
    printf("%d\n",ans);
}
int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
}