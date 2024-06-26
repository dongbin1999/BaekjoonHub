#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define UNIQUE(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
#define ix(x) (lower_bound(xc.begin(),xc.end(),x)-xc.begin())
#define iy(y) (lower_bound(yc.begin(),yc.end(),y)-yc.begin())
vector<int> xc={0,100000},yc={0,100000};
ll d[1005][1005];

int main(){
    int n;scanf("%d",&n);
    vector<pii> v(n);
    for(auto &[x,y]:v){
        scanf("%d%d",&x,&y);
        int a=max(x,y),b=x+y;
        xc.push_back(a),yc.push_back(b);
    }
    UNIQUE(xc);UNIQUE(yc);
    int r=xc.size(),c=yc.size();
    for(auto [x,y]:v){
        int a=max(x,y),b=x+y;
        d[ix(a)][iy(b)]+=x-y;
    }
    ll ans=0;
    for(int i=1;i<r;i++)for(int j=1;j<c;j++){
        d[i][j]+=d[i-1][j]+d[i][j-1]-d[i-1][j-1];
        if(d[i][j]>0&&i+1<r&&j+1<c)
            ans+=(xc[i+1]-xc[i])*(yc[j+1]-yc[j]);
    }
    printf("%lld",ans);
}