#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
pii dir[4]={{0,1},{1,0},{0,-1},{-1,0}};

int dig(int x){
    while(x>=10){
        int nx=0;
        while(x)nx+=x%10,x/=10;
        x=nx;
    }
    return x;
}

void solve(){
    int k,m;scanf("%d%d",&k,&m);
    map<pii,int> idx;
    vector<pii> ans={{1,0}};idx[{1,0}]=0;
    int d=0,num=1;
    pii iter={-1,-1};
    while(ans.size()<k){
        d=(d+1)%4;
        num=dig(num*m);
        if(idx.count({num,d})){
            iter={idx[{num,d}],ans.size()-1};
            break;
        }
        idx[{num,d}]=ans.size();
        ans.push_back({num,d});
    }
    ll x=0,y=0;
    for(auto [num,d]:ans){
        auto [dx,dy]=dir[d];
        x+=dx*num,y+=dy*num;
    }
    if(ans.size()<k){
        auto [l,r]=iter;
        ll len=r-l+1,a=(k-ans.size())/len,b=(k-ans.size())%len;
        ll ix=0,iy=0;
        for(int i=l;i<=r;i++){
            auto [num,d]=ans[i];
            auto [dx,dy]=dir[d];
            ix+=dx*num,iy+=dy*num;
            if(i<l+b)x+=dx*num,y+=dy*num;
        }
        x+=ix*a,y+=ix*b;
    }
    printf("%lld %lld\n",x,y);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}