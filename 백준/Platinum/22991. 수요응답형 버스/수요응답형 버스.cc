#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<pii> a(n),b(m);
    for(auto &[c,d]:a)scanf("%d%d",&d,&c),d*=-1;
    for(auto &[c,d]:b)scanf("%d%d",&d,&c),d*=-1;
    sort(a.begin(),a.end(),greater<pii>()),sort(b.begin(),b.end(),greater<pii>());
    int ai=0,bi=0,ans=0;
    multiset<int> se;
    while(bi<m){
        int bt=b[bi].first;
        while(ai<n&&bt<=a[ai].first)se.insert(a[ai++].second);
        auto it=se.lower_bound(b[bi].second);
        if(it!=se.end())se.erase(it),ans++;
        bi++;
    }
    printf("%d",ans);
}