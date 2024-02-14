#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int main(){
    int n,k;scanf("%d%d",&n,&k);
    vector<pii> v(n);
    for(auto&[p,q]:v)scanf("%d%d",&p,&q);
    double l=0.0,r=1.0,mid,ans=0.0;
    int t=30;while(t--){
        mid=(l+r)/2.0;
        sort(v.begin(),v.end(),[&](pii a,pii b){return -mid*a.second+a.first>-mid*b.second+b.first;});
        ll a=0,b=0;
        for(int i=0;i<k;i++)a+=v[i].first,b+=v[i].second;
        if(a>=mid*b)ans=max(ans,mid),l=mid;
        else r=mid;
    }
    printf("%.8lf\n",ans);
}