#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main() {
    int n;scanf("%d",&n);
    vector<pii> v;
    while(n--){
        int a,b;scanf("%d%d",&a,&b);
        if(b)v.push_back({a,b});
    }
    sort(v.begin(),v.end(),[](pii a,pii b){
        return a.first*b.second>b.first*a.second;});
    int ans=0,delay=0;
    for(auto [a,b]:v){
        int add=((delay)*a+b)%40000;
        ans=(ans+add)%40000,delay=(delay+add)%40000;
    }
    printf("%d",ans);
}