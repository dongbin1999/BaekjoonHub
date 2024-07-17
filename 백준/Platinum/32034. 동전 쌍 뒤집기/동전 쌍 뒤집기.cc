#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[2000000];

void solve(){
    int n;scanf("%d",&n);
    scanf("%s",s);
    vector<ll> v;
    for(int i=0;i<n;i++){
        if(s[i]=='T')v.push_back(i);
    }
    if(v.size()%2){
        printf("-1\n");return;
    }
    ll ans=0;
    vector<ll> vv;
    for(auto i:v){
        vv.push_back(i);
        while(vv.size()>=2){
            ll x=vv[vv.size()-2],y=vv[vv.size()-1];
            if((y-x)%2==0)break;
            else ans+=(y-x)/2ll*2ll+1,vv.pop_back(),vv.pop_back();
        }
    }
    if(!vv.empty()){
        printf("-1\n");
    }
    else printf("%lld\n",ans);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}