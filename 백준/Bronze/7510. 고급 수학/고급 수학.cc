#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int tc;scanf("%d",&tc);
    for(int i=1;i<=tc;i++){
        printf("Scenario #%d:\n",i);
        vector<ll> v(3);
        for(int j=0;j<3;j++)scanf("%lld",&v[j]);
        sort(v.begin(),v.end());
        ll a=v[0],b=v[1],c=v[2];
        if(c*c==a*a+b*b)printf("yes\n\n");
        else printf("no\n\n");
    }
    return 0;
}