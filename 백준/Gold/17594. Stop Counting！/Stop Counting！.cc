#include<bits/stdc++.h>
using namespace std;
typedef pair<double,int> pdi;

int main(){
    int n;scanf("%d",&n);
    vector<double> v(n+2);
    vector<pdi> l(n+2),r(n+2);
    for(int i=1;i<=n;i++)scanf("%lf",&v[i]);
    int x=0;double sum=0.0;
    for(int i=1;i<=n;i++){
        x++,sum+=v[i];
        l[i]=max(l[i-1],{sum/x,x});
    }
    x=0,sum=0.0;
    for(int i=n;i>=1;i--){
        x++,sum+=v[i];
        r[i]=max(r[i+1],{sum/x,x});
    }
    double ans=0.0;
    for(int i=0;i<=n;i++){
        auto [l1,l2]=l[i];
        auto [r1,r2]=r[i+1];
        ans=max(ans,(l1*l2+r1*r2)/(l2+r2));
    }
    printf("%.12lf",ans);
    return 0;
}