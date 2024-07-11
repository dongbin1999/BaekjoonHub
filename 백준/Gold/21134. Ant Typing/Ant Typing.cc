#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
ll d[10][10];

int main(){
    string s;cin>>s;
    map<pii,ll> ma;
    for(int i=1;i<s.size();i++){
        int x=s[i-1]-'0',y=s[i]-'0';
        ma[{min(x,y),max(x,y)}]++;
    }
    vector<ll> v={1,2,3,4,5,6,7,8,9};
    ll S=s[0]-'0';
    ll ans=2e18;
    do{
        ll tmp=0;
        for(ll i=0;i<9;i++)if(S==v[i])tmp+=i;
        for(int i=0;i<8;i++)for(int j=i+1;j<9;j++)
            d[min(v[i],v[j])][max(v[i],v[j])]=j-i;
        for(auto [x,y]:ma)
            tmp+=d[x.first][x.second]*y;
        ans=min(ans,tmp);
    }while(next_permutation(v.begin(),v.end()));
    printf("%lld",ans+s.size());
    return 0;
}