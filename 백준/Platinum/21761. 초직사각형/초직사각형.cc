#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,k;scanf("%d%d",&n,&k);
    vector<ll> v(4);
    for(int i=0;i<4;i++)scanf("%lld",&v[i]);
    vector<priority_queue<ll>> a(4);
    while(n--){
        char c;ll l;scanf(" %c %lld",&c,&l);
        a[c-'A'].push(l);
    }
    vector<pair<char,ll>> ans;
    while(k--){
        vector<__int128> add(4);
        for(int i=0;i<4;i++){
            if(a[i].empty())continue;
            add[i]=a[i].top();
            for(int j=0;j<4;j++)if(i!=j)add[i]*=v[j];
        }
        int idx=max_element(add.begin(),add.end())-add.begin();
        ans.push_back({idx+'A',a[idx].top()}),v[idx]+=a[idx].top(),a[idx].pop();
    }
    for(auto [a,b]:ans)printf("%c %lld\n",a,b);
    return 0;
}