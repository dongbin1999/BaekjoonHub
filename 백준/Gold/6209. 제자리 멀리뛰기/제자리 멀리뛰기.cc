#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int d,n,m;scanf("%d%d%d",&d,&n,&m);
    vector<int> v;
    while(n--){
        int x;scanf("%d",&x);
        v.push_back(x);
    }
    v.push_back(d);
    sort(v.begin(),v.end());
    int l=0,r=d,mid,ans=0;
    while(l<=r){
        mid=l+r>>1;
        int cnt=0,pre=0;
        for(auto i:v)if(i-pre<mid)cnt++;else pre=i;
        if(cnt<=m)ans=max(ans,mid),l=mid+1;
        else r=mid-1;
    }
    printf("%d",ans);
    return 0;
}