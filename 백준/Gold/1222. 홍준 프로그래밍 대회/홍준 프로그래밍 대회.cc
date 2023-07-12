#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    vector<int> cnt(2000001);
    while(n--){
        int x;scanf("%d",&x);
        for(int i=1;i*i<=x;i++)
            if(x%i==0){
                cnt[i]++;
                if(x/i^i)cnt[x/i]++;
            }
    }
    ll ans=0;
    for(ll i=1;i<=2000000;i++)
        if(cnt[i]>1)ans=max(ans,i*cnt[i]);
    printf("%lld",ans);
    return 0;
}