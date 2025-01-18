#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[500001];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&sum[i]),sum[i]+=sum[i-1];
    vector<ll> b(m);
    for(int i=0;i<m;i++)scanf("%lld",&b[i]);
    ll l=1,r=2e12,mid,ans=r;
    while(l<=r){
        mid=(l+r)/2;
        bool ok=0;
        sort(b.begin(),b.end());
        do{
            int L=1;
            for(auto x:b){
                int le=L,ri=n,middle,mx=L-1;
                while(le<=ri){
                    middle=(le+ri)/2;
                    if(sum[middle]-sum[L-1]<=mid*x)mx=max(mx,middle),le=middle+1;
                    else ri=middle-1;
                }
                if(L>mx)continue;
                else L=mx+1;
            }
            if(L>n){ok=1;break;}
        }while(next_permutation(b.begin(),b.end()));
        if(ok)ans=min(ans,mid),r=mid-1;
        else l=mid+1;
    }
    printf("%lld",ans);
}