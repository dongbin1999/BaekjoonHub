#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,m,t;scanf("%d%d%d",&n,&m,&t);
    unordered_map<int,int> ma;
    while(t--){
        int x,y;scanf("%d%d",&x,&y);
        ma[x]=min(m,ma[x]+y);
        unordered_map<int,int> v;
        for(auto [nx,ny]:ma){
            int val=ny/5;
            if(!val)continue;
            for(int dx=-1;dx<=1;dx++)
                if(nx+dx>=1&&nx+dx<=n)v[nx+dx]=min(m,v[nx+dx]+val);
        }
        ma=v;
        ll ans=0;
        for(auto [a,b]:ma)ans+=b;
        printf("%lld\n",ans);
    }
}