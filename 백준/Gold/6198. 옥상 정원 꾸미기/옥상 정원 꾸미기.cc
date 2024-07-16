#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    vector<int> v;
    ll ans=0;
    while(n--){
        int x;scanf("%d",&x);
        while(!v.empty()&&v.back()<=x)v.pop_back();
        ans+=v.size();
        v.push_back(x);
    }
    printf("%lld",ans);
}