#include<bits/stdc++.h>
using namespace std;
typedef double d;
typedef array<d,3> arr;
void solve(){
    d x,s,r,t,n;scanf("%lf%lf%lf%lf%lf",&x,&s,&r,&t,&n);
    vector<arr> v(n);
    d ans=0.0;
    for(auto &[b,e,w]:v)
        scanf("%lf%lf%lf",&b,&e,&w);
    vector<d> vv={0.0};
    for(auto [b,e,w]:v)vv.push_back(b),vv.push_back(e);
    vv.push_back(x);
    for(int i=1;i<vv.size();i+=2)v.push_back({0,vv[i]-vv[i-1],0});
    sort(v.begin(),v.end(),[](arr p,arr q){return p[2]<q[2];});
    for(auto [b,e,w]:v){
        d dist=e-b,time=dist/(w+r);
        if(t>=time)ans+=time,t-=time;
        else{
            ans+=t,dist-=t*(w+r),t=0;
            ans+=dist/(w+s);
        }
    }
    printf("%.10lf\n",ans);
}
int main(){
    int tc;scanf("%d",&tc);
    for(int i=1;i<=tc;i++){
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}